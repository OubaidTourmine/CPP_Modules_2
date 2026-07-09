#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    this->date = "";
    this->exchange_rate = "";
    this->value = 0.0;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    this->date = other.date;
    this->value = other.value;
    this->exchange_rate = other.exchange_rate;
    this->data_base = other.data_base;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        this->date = other.date;
        this->value = other.value;
        this->exchange_rate = other.exchange_rate;
        this->data_base = other.data_base;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}
