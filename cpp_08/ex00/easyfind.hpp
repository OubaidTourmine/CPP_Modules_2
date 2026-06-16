#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <vector>
#include <stdexcept>
#include <iostream>

template <typename T>
void easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
    {
        throw std::exception();
    }
    else
    {
        std::cout << "Value found: " << *it << std::endl;
    }
}

#endif
