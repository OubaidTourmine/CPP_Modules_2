#include "Span.hpp"

void Span::addNumber(unsigned int number)
{

    try
    {
        if(vec.size() < _N)
        {
            vec.push_back(number);
        }
        else
        {
            throw std::exception();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    srand(time(NULL));
	for (unsigned int i = 0; i < _N; i++)
	{
		int random_int = rand() % 10000;
		vec.push_back(random_int);
	}
    try
    {
        if (vec.size() + std::distance(begin, end) <= _N)
        {
            vec.insert(vec.end(), begin, end);
        }
        else
        {
            throw std::exception();
        }
    }
    catch(const std::exception& e)
