#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5), target("default")
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential Pardon Form", 25, 5), target(target)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), target(other.target)
{
    target = other.target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
