#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("default"), is_signed(false), grade_to_sign(150), grade_to_execute(150)
{
    
}

AForm::AForm(const std::string &name, int grade_to_sign, int grade_to_execute) : name(name), is_signed(false), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
	if (this->grade_to_sign < 1 || this->grade_to_execute < 1)
		throw GradeTooHighException();
	else if (this->grade_to_sign > 150 || this->grade_to_execute > 150)
		throw GradeTooLowException();
}

AForm::~AForm()
{

}

AForm::AForm(const AForm &other) : name(other.name), is_signed(other.is_signed), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
{

}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        is_signed = other.is_signed;
    }
    return (*this);
}

const std::string &AForm::getName() const
{
    return this->name;
}


int AForm::getGradeToSign() const
{
    return this->grade_to_sign;
}

int AForm::getGradeToExecute() const
{
    return this->grade_to_execute;
}
