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
    {
        std::cerr << e.what() << '\n';
    }
}

int Span::shortestSpan()
{
    try
    {

        if(vec.size() < 2)
            throw std::exception();
        std::sort(vec.begin(), vec.end());
        int tmp = vec[1] - vec[0];
        for(size_t i = 2; i < vec.size() ; i++)
        {        if(vec[i] - vec[i - 1] < tmp)
            tmp = vec[i] - vec[i - 1];
        }
        return tmp;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}

int Span::longestSpan()
{
    try{

        if(vec.size() < 2)
            throw std::exception();
        std::sort(vec.begin(), vec.end());
        return vec.back() - vec.front();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}

