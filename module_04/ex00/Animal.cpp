//
// Created by mosmont on 3/10/25.
//

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "\033[32;1mDefault constructor for Animal class\033[0m" << std::endl;
	this->m_type = "Base animal";
}

Animal::Animal(const Animal &other)
{
	std::cout << "\033[32;1mCopy constructor for Animal class\033[0m" << std::endl;
	this->m_type = other.m_type;
}

Animal	&Animal::operator=(const Animal &other)
{
	std::cout << "\033[32;1mAffectation constructor for Animal class\033[0m" << std::endl;
	if (&other != this)
		this->m_type = other.m_type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "\033[31;1mDestructor class for Animal class\033[0m" << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal base sound" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->m_type);
}