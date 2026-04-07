#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade)
{
	if (this->grade < 1)
		throw GradeTooHighException();
	else if (this->grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        this->grade = other.grade;
    return (*this);
}

const std::string &Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::incrementGrade()
{
	if (grade == 1)
		throw GradeTooHighException();
	else
		grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade == 150)
		throw GradeTooLowException();
	else
		grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}

void Bureaucrat::signForm(AForm &Aform)
{
	try
	{
		Aform.beSigned(*this);
		std::cout << getName() << " signed " << Aform.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << Aform.getName() << " because " << e.what() << std::endl;
	}	
}

void Bureaucrat::executeForm(const AForm &AForm)
{
	try
	{
		AForm.execute(*this);
		std::cout << this->getName() << " executed " << AForm.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
}