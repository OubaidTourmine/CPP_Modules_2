#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cmath>


enum    e_type
{
    SPECIAL = 0,
    CHAR = 1,
    INT = 2,
    FLOAT = 3,
    DOUBLE = 4,
    INVALID = -1
};

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();
    public:
        static void	convert(const std::string& str);
};




#endif
