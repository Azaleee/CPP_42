//
// Created by mosmont on 3/10/25.
//

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat base constructor called" << std::endl;
	this->m_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	this->m_type = other.m_type;
}

WrongCat	WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat affectation constructor called" << std::endl;
	if (this != &other)
		this->m_type = other.m_type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Miaouuuuuuu Miaouuuu" << std::endl;
}