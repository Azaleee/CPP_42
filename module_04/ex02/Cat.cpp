//
// Created by mosmont on 3/10/25.
//

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "\033[32;1m\tCat base constructor called\033[0m" << std::endl;
	this->m_type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "\033[32;1m\tCat copy constructor called\033[0m" << std::endl;
	this->m_type = other.m_type;
	this->brain = new Brain(*other.brain);
}

Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "\033[32;1m\tCat affectation constructor called\033[0m" << std::endl;
	if (this != &other)
	{
//		Copie les membres de Animal vers this
		Animal::operator=(other);
		this->brain = new Brain(*other.brain);
		this->m_type = other.m_type;
	}
	return (*this);
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "\033[31;1mCat destructor called\033[0m" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Miaouuuuu" << std::endl;
}

void	Cat::setIdea(int i, std::string str)
{
	this->brain->setIdea(i, str);
}

std::string Cat::getIdea(int i)
{
	return (this->brain->getIdea(i));
}