//
// Created by mosmont on 3/13/25.
//

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	this->m_type = AMateria::m_type;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	this->m_type = AMateria::m_type;
}

Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
		this->m_type = other.m_type;
	return (*this);
}

AMateria *Ice::clone() const
{
	return (new Ice());
}

void Ice::use(int &target)
{
	std::cout << "* shoots an ice bolt at " << target.name << " *" << std::endl;
}