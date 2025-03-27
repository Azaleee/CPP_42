//
// Created by mosmont on 3/10/25.
//

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "\033[32;1mWrongCat base constructor called\033[0m" << std::endl;
	this->m_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "\033[32;1mWrongCat copy constructor called\033[0m" << std::endl;
	this->m_type = other.m_type;
}

WrongCat	WrongCat::operator=(const WrongCat &other)
{
	std::cout << "\033[32;1mWrongCat affectation constructor called\033[0m" << std::endl;
	if (this != &other)
		this->m_type = other.m_type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "\033[31;1mWrongCat destructor called\033[0m" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Miaouuuuuuu Miaouuuu" << std::endl;
}