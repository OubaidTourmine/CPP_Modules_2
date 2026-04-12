#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat director("Director", 1);
    Bureaucrat intern("Intern", 150);
    Bureaucrat employee("Employee", 75);
    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robo("Bender");
    PresidentialPardonForm pardon("Fry");

    std::cout << "--- Attempt signing with low-grade intern ---\n";
    intern.signForm(shrub);
    intern.signForm(robo);
    intern.signForm(pardon);

	std::cout << "\n--- Attempt signing with mid-grade employee ---\n";
    employee.signForm(shrub);
    employee.signForm(robo);
    employee.signForm(pardon);


