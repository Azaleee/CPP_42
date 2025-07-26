//
// Created by mosmont on 3/14/25.
//

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat test("test", -2);
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "\033[31;1mError with construction : " << e.what() << "\033[0m" << std::endl;
	}

	try
	{
		Bureaucrat test2("test2", 200);
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "\033[31;1mError with construction : " << e.what() << "\033[0m" << std::endl;
	}

	std::cout << std::endl;

	Bureaucrat test3("Matias", 100);
	std::cout << test3 << std::endl;
	test3.incGrade();
	test3.decGrade();

	std::cout << std::endl;

	Bureaucrat test4("Mathias", 3);
	for (int i = 0; i < 3; i++)
	{
		try
		{
			test4.incGrade();
		}
		catch (Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << "\033[31;1mError : " << e.what() << "\033[0m" << std::endl;
		}
	}
	std::cout << test4 << std::endl;

	std::cout << std::endl;

	Bureaucrat test5("Matthias", 148);
	for (int i = 0; i < 3; i++)
	{
		try
		{
			test5.decGrade();
		}
		catch (Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << "\033[31;1mError : " << e.what() << "\033[0m" << std::endl;
		}
	}
	std::cout << test5 << std::endl;
}