#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const &other);
		Intern &operator=(Intern const &other);
		~Intern();

		AForm *makeForm(std::string const &formName, std::string const &targetName) const;

		class FormNotFoundException : public std::exception
		{
			public:
				char const *what() const throw()
				{
					return "Intern: requested form name not found.";
				}
		};
};