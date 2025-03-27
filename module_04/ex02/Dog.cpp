//
// Created by mosmont on 3/10/25.
//

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "\033[32;1m\tDog base constructor called\033[0m" << std::endl;
	this->m_type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "\033[32;1m\tDog copy constructor called\033[0m" << std::endl;
	this->m_type = other.m_type;
	this->brain = new Brain(*other.brain);
}

Dog	&Dog::operator=(const Dog &other)
{
	std::cout << "\033[32;1m\tDog copy constructor called\033[0m" << std::endl;
	if (this != &other)
	{
//		Copie les membres de Animal vers this
		Animal::operator=(other);
		this->brain = new Brain(*other.brain);
		this->m_type = other.m_type;
	}
	return (*this);
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "\033[31;1mDog destructor called\033[0m" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Ouafff Ouafff" << std::endl;
}

void	Dog::setIdea(int i, std::string str)
{
	this->brain->setIdea(i, str);
}

std::string Dog::getIdea(int i)
{
	return (this->brain->getIdea(i));
}