//
// Created by mosmont on 3/10/25.
//

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "\033[32;1m\tDog base constructor called\033[0m" << std::endl;
	this->m_type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "\033[32;1m\tDog copy constructor called\033[0m" << std::endl;
	this->m_type = other.m_type;
}

Dog	Dog::operator=(const Dog &other)
{
	std::cout << "\033[32;1m\tDog copy constructor called\033[0m" << std::endl;
	if (this != &other)
		this->m_type = other.m_type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "\033[31;1mDog destructor called\033[0m" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Ouafff Ouafff" << std::endl;
}