#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("default"), is_signed(false), grade_to_sign(150), grade_to_execute(150)
{
}

Form::Form(const std::string &name, int grade_to_sign, int grade_to_execute) : name(name), is_signed(false), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
	if (this->grade_to_sign < 1 || this->grade_to_execute < 1)
		throw GradeTooHighException();
	else if (this->grade_to_sign > 150 || this->grade_to_execute > 150)
		throw GradeTooLowException();
}

Form::~Form()
{

}

Form::Form(const Form &other) : name(other.name), is_signed(other.is_signed), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
{

}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        is_signed = other.is_signed;
    }
    return (*this);
}

const std::string &Form::getName() const
{
    return this->name;
}


int Form::getGradeToSign() const
{
    return this->grade_to_sign;
}

int Form::getGradeToExecute() const
{
    return this->grade_to_execute;
}


const char *Form::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}


void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= getGradeToSign())
        is_signed = true;
    else
        throw GradeTooLowException();
}

bool Form::is_Signed() const
{
    return is_signed;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form \"" << form.getName() << "\" | Signed: ";
	if (form.is_Signed())
		out << "yes";
	else
		out << "no";
	out << " | Grade to sign: " << form.getGradeToSign() << " | Grade to execute: " << form.getGradeToExecute();
	return (out);
}