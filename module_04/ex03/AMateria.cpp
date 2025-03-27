//
// Created by mosmont on 3/13/25.
//

#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(const std::string &type) : m_type(type) {}

AMateria::AMateria(const AMateria &other)
{
	this->m_type = other.m_type;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		this->m_type = other.m_type;
	return (*this);
}

AMateria::~AMateria() {}

const std::string &AMateria::getTYpe() const
{
	return (this->m_type);
}

void AMateria::use(int &target) {}