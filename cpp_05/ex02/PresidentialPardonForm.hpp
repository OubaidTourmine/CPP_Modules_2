#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
        void executeAction()const;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
};

#endif