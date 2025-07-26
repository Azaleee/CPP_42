#include "PresidentialPardonForm.hpp"
#include <cstdlib>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 45) {};

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 45), target(target) {};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm() {};

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
		this->target = other.target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw PresidentialPardonForm::FormNotSigned();
	if (executor.getGrade() > this->getGradeToExecute())
		throw PresidentialPardonForm::GradeTooLowException();
	std::cout << "[" << target << "] " << "has been pardoned by Zaphold Beeblebrox" << std::endl;
}