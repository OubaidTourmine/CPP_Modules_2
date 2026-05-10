#include "ScalarConverter.hpp"
#include "type.cpp"


ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{

}

void	typeSpecial(const std::string& str)
{
	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible" << std::endl; 
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void	typeChar(const std::string& str)
{
	if(str.length() == 1)
	{
		char c = str[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: '" << static_cast<int>(c) << "'" << std::endl;
		std::cout << "float: '" << static_cast<float>(c) << ".0f'" << std::endl;
		std::cout << "double: '" << static_cast<double>(c) << ".0'" << std::endl;
	}
	else
	{
		std::cout << "Invalid input !\n";
		return ;
	}
}

void	typeInt(const std::string& str)
{
	long i = atol(str.c_str());
	if (i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min())
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: '" <<  static_cast<int>(i) << "'" << std::endl;
	std::cout << "float: '" << static_cast<float>(i) << ".0f'" << std::endl;
	std::cout << "double: '" << static_cast<double>(i) << ".0'" << std::endl;
}

void	typeDouble(const std::string& str)
{
	double d = atof(str.c_str());
	if (d > std::numeric_limits<double>::max() || d < std::numeric_limits<double>::min())
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: '" << static_cast<int>(d) << "'" << std::endl;
	if (d == (int)d)
	{
		std::cout << "float: '" << static_cast<float>(d) << ".0f'" << std::endl;
		std::cout << "double: '" << static_cast<double>(d) << ".0'" << std::endl;
	}	
	else
    {
		std::cout << "float: '" << static_cast<float>(d) << "f'" << std::endl;
		std::cout << "double: '" << static_cast<double>(d) << "'" << std::endl;
	}
}

void	typeFloat(const std::string& str)
{
	float f = static_cast<float>(atof(str.c_str()));
	if (f > std::numeric_limits<float>::max() || f < std::numeric_limits<float>::min())
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: '" << static_cast<int>(f) << "'" << std::endl;
	if (f == (int)f)
	{
		std::cout << "float: '" << static_cast<float>(f) << ".0f'" << std::endl;
		std::cout << "double: '" << static_cast<double>(f) << ".0'" << std::endl;
	}	
	else
    {
		std::cout << "float: '" << static_cast<float>(f) << "f'" << std::endl;
		std::cout << "double: '" << static_cast<double>(f) << "'" << std::endl;
	}
}

void	ScalarConverter::convert(const std::string& str)
{
	size_t length = str.length();
	e_type type;
	type = whichType(str, length);
	if(type == SPECIAL)
		typeSpecial(str);
	if(type == CHAR)
		typeChar(str);
	else if (type == INT)
		typeInt(str);
	else if (type == FLOAT)
		typeFloat(str);
	else if (type == DOUBLE)
		typeDouble(str);	
	else if (type == INVALID)
		std::cout << "Invalid input !\n";
}
