//
// Created by mosmont on 3/10/25.
//

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "\033[32;1m\tCat base constructor called\033[0m" << std::endl;
	this->m_type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "\033[32;1m\tCat copy constructor called\033[0m" << std::endl;
	this->m_type = other.m_type;
}

Cat	Cat::operator=(const Cat &other)
{
	std::cout << "\033[32;1m\tCat affectation constructor called\033[0m" << std::endl;
	if (this != &other)
		this->m_type = other.m_type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "\033[31;1mCat destructor called\033[0m" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Miaouuuuu" << std::endl;
}