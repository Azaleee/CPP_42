//
// Created by mosmont on 3/10/25.
//

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "\033[32;1mDefault constructor for WrongAnimal class\033[0m" << std::endl;
	this->m_type = "Base animal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "\033[32;1mCopy constructor for WrongAnimal class\033[0m" << std::endl;
	this->m_type = other.m_type;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "\033[32;1mAffectation constructor for WrongAnimal class\033[0m" << std::endl;
	if (&other != this)
		this->m_type = other.m_type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "\033[31;1mDestructor class for WrongAnimal class\033[0m" << std::endl;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal base sound" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->m_type);
}