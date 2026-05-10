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
