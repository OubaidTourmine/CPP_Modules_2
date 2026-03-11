#include "Bureaucrat.hpp"

int main ()
{
    try {
        Bureaucrat Bureaucrat1("Oubaid", 1);
        std::cout << Bureaucrat1 << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        Bureaucrat Bureaucrat2("Tourmine", 15);
        std::cout << Bureaucrat2 << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}