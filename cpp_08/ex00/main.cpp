#include "easyfind.hpp"


int main ()
{
    std::vector<int> vec;
    for (int i = 0; i < 10; i++)
    {
        vec.push_back(i);
    }
    try
    {
        easyfind(vec, 5);
        easyfind(vec, 15);
    }
    catch (std::exception &e)
    {
        std::cout << "out_of_range: Value not found" << std::endl;

    }
    return 0;
}