#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool is_signed;
        const int grade_to_sign;
        const int grade_to_execute;
        virtual void executeAction() const = 0;
    public:
        void execute(Bureaucrat const & executor) const;
        AForm();
        AForm(const std::string &name, int grade_to_sign, int grade_to_execute);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();
        const std::string &getName() const;
        int getGradeToSign() const;
