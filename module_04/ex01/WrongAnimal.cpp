//
// Created by mosmont on 3/10/25.
//

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Default constructor for WrongAnimal class" << std::endl;
	this->m_type = "Base animal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "Copy constructor for WrongAnimal class" << std::endl;
	this->m_type = other.m_type;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "Affectation constructor for WrongAnimal class" << std::endl;
	if (&other != this)
		this->m_type = other.m_type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor class for WrongAnimal class" << std::endl;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal base sound" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->m_type);
}