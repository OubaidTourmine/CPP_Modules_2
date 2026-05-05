#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern intern;
    AForm* form;

    //PresidentialPardonForm sign 25 exec 5
    try {
        Bureaucrat bureaucrat1("Oubaid", 5);
        form = intern.makeForm("presidential pardon", "Zaphod");

        std::cout << "\n--- PresidentialPardonForm ---" << std::endl;
        std::cout << *form << std::endl;
        // bureaucrat1.signForm(*form);
        bureaucrat1.executeForm(*form);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    delete form;

    //RobotomyRequestForm sign 72 exec 45
    try {
        Bureaucrat bureaucrat2("Alice", 45);
        form = intern.makeForm("robotomy request", "Bender");

        std::cout << "\n--- RobotomyRequestForm ---" << std::endl;
        std::cout << *form << std::endl;
        bureaucrat2.signForm(*form);
        bureaucrat2.executeForm(*form);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    delete form;

    //ShrubberyCreationForm sign 145 exec 137
    try {
        Bureaucrat bureaucrat3("Bob", 137);
        form = intern.makeForm("shrubbery creation", "home");

        std::cout << "\n--- ShrubberyCreationForm ---" << std::endl;
        std::cout << *form << std::endl;
        bureaucrat3.signForm(*form);
        bureaucrat3.executeForm(*form);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    delete form;

    //Execute unsigned form should fail
    try {
        Bureaucrat bureaucrat4("Charlie", 5);
        form = intern.makeForm("presidential pardon", "NotSigned");

        std::cout << "\n--- Try to execute unsigned form ---" << std::endl;
        bureaucrat4.executeForm(*form);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    delete form;

    return 0;
}