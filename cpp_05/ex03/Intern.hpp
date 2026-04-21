#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

// class AForm;

class Intern
{
    private:
        AForm *createRobotomy(const std::string &form_target);
        AForm *createShrubbery(const std::string &form_target);
        AForm *createPardon(const std::string &form_target);
	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();
		AForm *makeForm(const std::string &form_name, const std::string &form_target) ;
};

#endif