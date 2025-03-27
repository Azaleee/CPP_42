//
// Created by mosmont on 3/10/25.
//

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "\033[32;1m\t\tBrain default constructor called\033[0m" << std::endl;
	for (int i = 0; i < NB_IDEAS; i++)
		this->ideas[i] = "Salut";
}

Brain::Brain(const Brain &other)
{
	std::cout << "\033[32;1m\t\tBrain copy constructor called\033[0m" << std::endl;
	for (int i = 0; i < NB_IDEAS; i++)
		this->ideas[i] = other.ideas[i];
}

Brain::~Brain()
{
	std::cout << "\033[31;1mBrain destructor called\033[0m" << std::endl;
}

Brain	&Brain::operator=(const Brain &other)
{
	std::cout << "\033[32;1m\t\tBrain affectation constructor called\033[0m" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < NB_IDEAS; i++)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

std::string	Brain::getIdea(int i)
{
	return (this->ideas[i]);
}

void	Brain::setIdea(int i, std::string str)
{
	this->ideas[i] = str;
}