#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat director("Director", 1);
    Bureaucrat intern("Intern", 150);
    Bureaucrat employee("Employee", 75);
    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robo("Bender");
    PresidentialPardonForm pardon("Fry");

    std::cout << "--- Attempt signing with low-grade intern ---\n";
    intern.signForm(shrub);
    intern.signForm(robo);
    intern.signForm(pardon);

	std::cout << "\n--- Attempt signing with mid-grade employee ---\n";
    employee.signForm(shrub);
    employee.signForm(robo);
    employee.signForm(pardon);


	std::cout << "\n--- Attempt signing with high-grade Director ---\n";
    director.signForm(shrub);
    director.signForm(robo);
    director.signForm(pardon);

    std::cout << "\n--- Try execute with intern ---\n";
    intern.executeForm(shrub);
    intern.executeForm(robo);
	intern.executeForm(pardon);
    std::cout << "\n--- Try execute with employee ---\n";
    employee.executeForm(shrub);
    employee.executeForm(robo);
	employee.executeForm(pardon);
    std::cout << "\n--- Try execute with Director ---\n";
    director.executeForm(shrub);
    director.executeForm(robo);
    director.executeForm(pardon);

    std::cout << "\n--- Direct calls to execute  ---\n";
    try 
    {
		shrub.execute(director); std::cout << "director executed shrub\n"; 
		shrub.execute(employee); std::cout << "employee executed shrub\n"; 
		shrub.execute(intern); std::cout << "intern executed shrub\n";
    } 
    catch (const std::exception &e) 
    {
		std::cerr << e.what() << "\n\n"; 
    }
    try 
    {
		robo.execute(director);  std::cout << "director executed robo\n";  
		robo.execute(employee);  std::cout << "employee executed robo\n";  
		robo.execute(intern);  std::cout << "intern executed robo\n";  
    } 
    catch (const std::exception &e) 
    {
		std::cerr << e.what() << "\n\n"; 
    }

    try 
    {
		pardon.execute(director);std::cout << "director executed pardon\n";
		pardon.execute(employee);std::cout << "employee executed pardon\n";
		pardon.execute(intern);std::cout << "intern executed pardon\n";
    }
	catch (const std::exception &e) 
    { 
		std::cerr << e.what() << "\n";
    }

    return 0;
}