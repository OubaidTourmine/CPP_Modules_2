#include "BitcoinExchange.hpp"

std::string trim(const std::string &str)
{
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end = str.find_last_not_of(" \t\n\r");
    if (start == std::string::npos)
        return "";
    else
        return str.substr(start, end - start + 1);
}

bool isLeapYear(int year)
{
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}


float BitcoinExchange::getExchangeRate(const std::string &date) const
{
    std::map<std::string, float>::const_iterator it = data_base.lower_bound(date);
    if (it == data_base.end())
        it--;
    else if (it->first != date)
    {
        if (it == data_base.begin())
            throw std::runtime_error("No earlier date available");
        it--;
    }
    return it->second;
}

bool BitcoinExchange::isValidDate(const std::string &date)
{

    if (date.length() != 10)
    {
        return false;
    }
    if (date[4] != '-' || date[7] != '-')
        return false;

    for (size_t i = 0; i < date.length(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (date[i] < '0' || date[i] > '9')
            return false;
    }
    
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((isLeapYear(year)))
        daysInMonth[1] = 29;
    if (day > daysInMonth[month -1])
        return false;
    return (true);
}

bool BitcoinExchange::isValidValue(const std::string &value)
{
    std::stringstream ss(value);
    float v;
    char c;

    if (!(ss >> v))
        return false;

    if (ss >> c)
        return false;

    if (v < 0)
        return false;

    if (v > 1000)
        return false;

    return true;
}

void BitcoinExchange::userInput(std::ifstream &file)
{
    std::string line;
    std::getline(file, line);
    std::string date;
    std::string value;
    while (std::getline(file, line))
    {
        if (trim(line).empty())
            continue;
 
        size_t pos = line.find('|');
        if (pos == std::string::npos)
        {
            std::cout << "Error: bad input => " << trim(line) << std::endl;
            continue;
        }
 
        date = trim(line.substr(0, pos));
        value = line.substr(pos + 1);
 
        if (!isValidDate(date))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (!isValidValue(value))
        {
            std::cout << "Error: bad number input. "<< std::endl;
            continue;
        }
 
        std::stringstream ss(value);
        float amount;
        ss >> amount;
 
        try
        {
            float rate = getExchangeRate(date);
            std::cout << date << " => " << amount << " = " << amount * rate << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}

void BitcoinExchange::parse_date(std::ifstream &file)
{
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        if (trim(line).empty())
            continue;
        std::stringstream ss(line);
        std::getline(ss, date, ',');
        std::getline(ss, exchange_rate, ',');
        std::istringstream iss(exchange_rate);
        if (iss >> value)
            data_base[date] = value;
    }
}


int main (int ac, char **av)
{
    if(ac != 2)
        return (std::cout << "Error: enter valid arguments." << std::endl, 1);
    std::ifstream inputFile(av[1]);
    if (!inputFile.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    if(!(std::string(av[1]).find(".txt") == std::string::npos || std::string(av[1]).find(".csv") == std::string::npos))
    {
        std::cout << "Error: file must be a .txt or .csv file." << std::endl;
        return 1;
    }
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        std::cerr << "Error: could not open .csv file." << std::endl;
        return 1;
    }

    BitcoinExchange btc;
    btc.parse_date(file);
    btc.userInput(inputFile);
    return 0;
}
