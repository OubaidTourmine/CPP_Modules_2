#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45), target("default")
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request Form", 72, 45), target(target)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target)
{
    target = other.target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if(this != &other)
    {
        target = other.target;
    }
    return (*this);
}

void RobotomyRequestForm::executeAction() const
{
    static int c = 0;
    c++;
    std::cout << "'drilling noises'... " << std::endl;
    if (c % 2 == 1)
        std::cout << "The robotomy of " << target << " failed" << std::endl;
    else
        std::cout << target << " has been robotomized successfully" << std::endl;
    }