#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
    public:
        unsigned int _N;
        std::vector<int> vec;
        Span(): _N(0) {}
        Span(unsigned int N): _N(N) {}
        Span(const Span &other)
        {
            *this = other;
        }
        Span &operator=(const Span &other)
        {
            if (this != &other)
            {
                this->_N = other._N;
                this->vec = other.vec;
            }
            return *this;
        }
        ~Span() {}
        void addNumber(unsigned int number);
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();
};

#endif
