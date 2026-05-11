#include "ScalarConverter.hpp"

int	is_Char(const std::string& str)
{
    for(int i = 0; str[i]; i++)
    {
        if (!isdigit(str[i]))
            return 1;
    }
    return 0;
}

int	is_Int(const std::string& str, size_t& len)
{
	int i = 0;
	int flag = 0;

	if (str[0] == '+')
	{
        flag = 1;
		i++;
	}
	while ((str[i] && len > 0 && len < 12) || (str[i] && flag == 0 && len > 0 && len < 11))
	{
		if (!isdigit(str[i]))
			return 0;
		i++;
	}
	return 1;
}

int	is_Float(const std::string& str, size_t& len)
{
    if (len > 0 && (str[len - 1] == 'f' || str[len - 1] == 'F'))
        return 1;
    return 0;
}

int	is_SpecialVal(const std::string& str)
{
	if (str == "nan" || str == "nanf" || str == "-inf" || str == "+inf" || str == "+inff" || str == "-inff")
		return 1;
	return 0;
}

e_type  whichType(const std::string& str, size_t& len)
{
    size_t  dot = str.find('.');
    size_t  f = str.find('f');
    size_t  minus = str.find('-');
    if (dot != std::string::npos && !isdigit(str[dot + 1]))
        return INVALID;
    if (minus != std::string::npos)
            return INT;
    if (dot == std::string::npos)
    {
        if (is_SpecialVal(str))
            return SPECIAL;
        else if (is_Char(str))
            return CHAR;
        else if (is_Int(str, len))
            return INT;
    }
    else if (f != std::string::npos && dot != std::string::npos)
    {
        if (is_Float(str, len))
            return FLOAT;
    }
    else if (f == std::string::npos && dot != std::string::npos)
        return DOUBLE;
    return INVALID;
}