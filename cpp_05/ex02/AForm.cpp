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


const char *AForm::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}


void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= getGradeToSign())
        is_signed = true;
    else
        throw GradeTooLowException();
}

bool AForm::is_Signed() const
{
    return is_signed;
}

std::ostream &operator<<(std::ostream &out, const AForm &Aform)
{
	out << "Form \"" << Aform.getName() << "\" | Signed: ";
	if (Aform.is_Signed())
		out << "yes";
	else
		out << "no";
	out << " | Grade to sign: " << Aform.getGradeToSign() << " | Grade to execute: " << Aform.getGradeToExecute();
	return (out);
}

const char *AForm::notSignedException::what() const throw()
{
	return ("Form can not be executed, because it is not signed!");
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (is_Signed() == false)
		throw notSignedException();
	if (getGradeToExecute() < executor.getGrade())
		throw GradeTooLowException();
	try
	{
		executeAction();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
		
}