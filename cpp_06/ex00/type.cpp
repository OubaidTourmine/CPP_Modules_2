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
