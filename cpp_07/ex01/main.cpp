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
