#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>

class BitcoinExchange
{
    private:
        std::string date;
        std::string exchange_rate;
        float value;
        std::map<std::string, float> data_base;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();
        void parse_date(std::ifstream &file);
        void userInput(std::ifstream &inputFile);
        bool isValidDate(const std::string &date);
        bool isValidValue(const std::string &value);
        float getExchangeRate(const std::string &date) const;



};

#endif