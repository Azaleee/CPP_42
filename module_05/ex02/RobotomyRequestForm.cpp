#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {};

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target) {};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm() {};

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		this->target = other.target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw RobotomyRequestForm::FormNotSigned();
	if (executor.getGrade() > this->getGradeToExecute())
		throw RobotomyRequestForm::GradeTooLowException();
	std::cout << "SOME DRILLING NOISES.............." << std::endl;
	std::srand(std::time(0));
	if (std::rand() % 2 == 0)
		std::cout << "[" << target << "] " << "has been robotomized." << std::endl;
	else
		std::cout << "The robotomy failed" << std::endl;
}