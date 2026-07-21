#include "RPN.hpp"

int main (int ac, char **av)
{
    if(ac != 2)
    {
        return(std::cerr << "Error: Invalid input" << std::endl), 1;
    }
    RPN rpn;
    if(rpn.ProcessInput(av[1]))
        return 1;
    return 0;
}
