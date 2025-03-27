//
// Created by mosmont on 3/6/25.
//

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->m_name = "default";
	this->m_hitPoint = 100;
	this->m_energyPoint = 50;
	this->m_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor with arg called" << std::endl;
	this->m_name = name;
	this->m_hitPoint = 100;
	this->m_energyPoint = 50;
	this->m_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	this->m_name = other.m_name;
	this->m_hitPoint = other.m_hitPoint;
	this->m_attackDamage = other.m_attackDamage;
	this->m_energyPoint = other.m_energyPoint;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap [" << this->m_name << "] Destructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap affectation constructor called" << std::endl;
	if (this != &other)
	{
		this->m_name = other.m_name;
		this->m_hitPoint = other.m_hitPoint;
		this->m_attackDamage = other.m_attackDamage;
		this->m_energyPoint = other.m_energyPoint;
	}
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->m_energyPoint != 0 && this->m_hitPoint > 0)
	{
		this->m_energyPoint--;
		std::cout << "ScavTrap " << this->m_name << " attacks " << target << ", causing " \
		<< this->m_attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->m_name << " is out of energy or is dead" \
		<< std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

