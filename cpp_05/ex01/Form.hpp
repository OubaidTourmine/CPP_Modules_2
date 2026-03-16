#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool is_signed;
        const int grade_to_sign;
        const int grade_to_execute;
    public:
        Form();
        Form(const std::string &name, int grade_to_sign, int grade_to_execute);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();
        const std::string &getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool is_Signed() const;
        void beSigned(Bureaucrat &bureaucrat);


        class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif

