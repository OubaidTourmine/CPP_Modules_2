#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

class Form;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
