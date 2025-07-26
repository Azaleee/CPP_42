//
// Created by mosmont on 3/14/25.
//

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat a("mosmont", 1);
	
	Intern intern;
	AForm *robot;

	try
	{
		robot = intern.makeForm("robotomy request", "Test");
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	a.signForm(*robot);
	a.executeForm(*robot);
}