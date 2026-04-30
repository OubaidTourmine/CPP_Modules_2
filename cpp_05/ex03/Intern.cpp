#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{

}

Intern::Intern(const Intern &other)
{
	(void) other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void) other;
	return (*this);
}

Intern::~Intern()
{

}

AForm *Intern::createRobotomy(const std::string &form_target)
{
    return (new RobotomyRequestForm(form_target));
}

AForm *Intern::createShrubbery(const std::string &form_target)
{
    return (new ShrubberyCreationForm(form_target));
}

AForm *Intern::createPardon(const std::string &form_target)
{
    return (new PresidentialPardonForm(form_target));
}

AForm *Intern::makeForm(const std::string &form_name, const std::string &form_target)
{
    std::string forms[3] = {"robotomy request", "shrubbery creation", "presidential pardon" };
    AForm *(Intern::*ptr[3])(const std::string &) = {&Intern::createRobotomy, &Intern::createShrubbery, &Intern::createPardon };

    for (int i = 0; i < 3; i++)
    {
        if (forms[i] == form_name)
        {
            std::cout << "Intern creates " << form_name << std::endl;
            return ((this->*ptr[i])(form_target));
        }
    }
    std::cerr << "Error : Unkown Type " << std::endl;
    return (NULL);
}


