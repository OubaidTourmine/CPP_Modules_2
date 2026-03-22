#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{   
    try {
        Bureaucrat Bureaucrat1("Oubaid", 3);
        Form form1("TaxForm1", 5, 10);
        std::cout << "\nBefore signing : " << form1.is_Signed() << std::endl;
        Bureaucrat1.signForm(form1);
        std::cout << "After signing : " << form1.is_Signed() << std::endl;
        std::cout << form1 << std::endl  << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    try {
        Bureaucrat Bureaucrat1("Oubaid", 3);
        Form form2("ContractForm1", 5, 10);
        std::cout << "\nBefore signing : " << form2.is_Signed() << std::endl;
        Bureaucrat1.signForm(form2);
        std::cout << "After signing : " << form2.is_Signed() << std::endl;
        std::cout << form2 << std::endl  << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    

    try {
        Bureaucrat Bureaucrat2("Tourmine", 11);
        Form form1("TaxForm1", 5, 10);
        std::cout << "\nBefore signing : " << form1.is_Signed() << std::endl;
        Bureaucrat2.signForm(form1);
        std::cout << "After signing : " << form1.is_Signed() << std::endl;
        std::cout << form1 << std::endl  << std::endl;
    }
