#include "iter.hpp"
#include <cctype>
#include <iostream>
#include <string>

template <typename T>
void printConst(T const &value)
{
	std::cout << value << " ";
}

void increment(int &value)
{
	value++;
}

void doubleValue(float &value)
{
	value = value * 2.0f;
}

void upperCase(std::string &value)
{
	for (std::string::size_type i = 0; i < value.length(); ++i)
		value[i] = std::toupper(value[i]);
}

int main()
{
	const std::size_t intCount = 5;
	int numbers[intCount] = {1, 2, 3, 4, 5};

	std::cout << "numbers before: ";
	iter(numbers, intCount, printConst<int>);
	std::cout << std::endl;

	iter(numbers, intCount, increment);

	std::cout << "numbers after increment: ";
	iter(numbers, intCount, printConst<int>);
	std::cout << std::endl << std::endl;

	const std::size_t constIntCount = 3;
	const int constNumbers[constIntCount] = {10, 20, 30};
	std::cout << "const numbers: ";
	iter(constNumbers, constIntCount, printConst<int>);
	std::cout << std::endl << std::endl;

	const std::size_t wordCount = 3;
	std::string words[wordCount] = {"hello", "world", "cpp"};
	std::cout << "words before: ";
	iter(words, wordCount, printConst<std::string>);
	std::cout << std::endl;

	iter(words, wordCount, upperCase);

	std::cout << "words after upperCase: ";
	iter(words, wordCount, printConst<std::string>);
	std::cout << std::endl << std::endl;

	const std::size_t floatCount = 3;
	float values[floatCount] = {1.5f, -2.0f, 0.25f};
	std::cout << "floats before: ";
	iter(values, floatCount, printConst<float>);
	std::cout << std::endl;

	iter(values, floatCount, doubleValue);

	std::cout << "floats after doubleValue: ";
	iter(values, floatCount, printConst<float>);
	std::cout << std::endl;

	return 0;
}

