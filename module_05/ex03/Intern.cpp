#include "Intern.hpp"

Intern::Intern() {};

Intern::~Intern() {};

Intern::Intern(Intern const &other) { (void)other; };

Intern &Intern::operator=(Intern const &other)
{
	(void)other;
	return *this;
};

static AForm *makeShrubbery(std::string const &target)
{ return new ShrubberyCreationForm(target); };
static AForm *makeRobotomy(std::string const &target)
{ return new RobotomyRequestForm(target); };
static AForm *makePresidential(std::string const &target)
{ return new PresidentialPardonForm(target); };

AForm *Intern::makeForm(std::string const &formName, std::string const &targetName) const
{
	std::string const names[3] = 
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm *(*creators[3])(std::string const &) =
	{
		&makeShrubbery,
		&makeRobotomy,
		&makePresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == names[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return creators[i](targetName);
		}
	}

	throw Intern::FormNotFoundException();
};