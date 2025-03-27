//
// Created by mosmont on 3/10/25.
//

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->m_name = "default FragTrap";
	this->m_hitPoint = 100;
	this->m_energyPoint = 100;
	this->m_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor with arg called" << std::endl;
	this->m_name = name;
	this->m_hitPoint = 100;
	this->m_energyPoint = 100;
	this->m_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	this->m_name = other.m_name;
	this->m_hitPoint = other.m_hitPoint;
	this->m_energyPoint = other.m_energyPoint;
	this->m_attackDamage = other.m_attackDamage;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap affectation constructor called" << std::endl;
	if (&other != this)
	{
		this->m_name = other.m_name;
		this->m_hitPoint = other.m_hitPoint;
		this->m_energyPoint = other.m_energyPoint;
		this->m_attackDamage = other.m_attackDamage;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap [" << this->m_name << "] Destructor called" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "HIGH FIVE GUYYYYYYS" << std::endl;
}