#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
        return (std::cerr << "Error: enter more values" << std::endl, 1);

    if (!parse_args(ac, av))
        return (std::cerr << "Error: enter valid values" << std::endl, 1);

    run();
    return (0);
}