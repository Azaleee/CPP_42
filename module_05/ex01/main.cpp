//
// Created by mosmont on 3/14/25.
//

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat a("mosmont", 40);
	
	Form b("Class", 5, 120);
	Form c("Hola", 42, 120);
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	a.signForm(b);
	a.signForm(c);

	std::cout << std::endl;
	std::cout << b << std::endl;
	std::cout << c;
}