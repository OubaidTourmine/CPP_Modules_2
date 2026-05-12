#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Please enter a char, int, float or double !\n";
		return (0);
	}

	ScalarConverter::convert(argv[1]);

	return (0);
}