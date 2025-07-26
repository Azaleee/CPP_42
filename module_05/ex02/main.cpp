//
// Created by mosmont on 3/14/25.
//

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat a("mosmont", 1);
	
	ShrubberyCreationForm b("Shrubbery");
	std::cout << b << std::endl;

	a.signForm(b);
	a.executeForm(b);

	std::cout << "================================" << std::endl;

	RobotomyRequestForm c("Robotomy");
	std::cout << c << std::endl;

	a.signForm(c);
	a.executeForm(c);

	std::cout << "================================" << std::endl;

	PresidentialPardonForm d("Presidential");
	std::cout << d << std::endl;

	a.signForm(d);
	a.executeForm(d);
}