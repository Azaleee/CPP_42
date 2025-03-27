//
// Created by mosmont on 3/6/25.
//

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : m_name("default")
{
	std::cout << "Default constructor called" << std::endl;
	this->m_hitPoint = 10;
	this->m_attackDamage = 0;
	this->m_energyPoint = 10;
}

ClapTrap::ClapTrap(const std::string name)
{
	std::cout << "Constructor with arg called" << std::endl;
	this->m_name = name;
	this->m_hitPoint = 10;
	this->m_attackDamage = 0;
	this->m_energyPoint = 10;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->m_name = other.m_name;
	this->m_attackDamage = other.m_attackDamage;
	this->m_energyPoint = other.m_energyPoint;
	this->m_hitPoint = other.m_hitPoint;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Affectation constructor called" << std::endl;
	if (this != &other)
	{
		this->m_name = other.m_name;
		this->m_hitPoint = other.m_hitPoint;
		this->m_energyPoint = other.m_energyPoint;
		this->m_attackDamage = other.m_attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "[" << this->m_name << "] Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->m_energyPoint != 0 && this->m_hitPoint > 0)
	{
		this->m_energyPoint--;
		std::cout << "ClapTrap " << this->m_name << " attacks " << target << ", causing " \
		<< this->m_attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->m_name << " is out of energy or is dead" \
		<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->m_hitPoint > 0)
	{
		this->m_hitPoint -= amount;
		std::cout << "ClapTrap " << this->m_name << " take " << amount << " points of damage"\
		<< std::endl;
	}
	else
		std::cout << "ClapTrap " << this->m_name << " is already die" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->m_energyPoint != 0 && this->m_hitPoint > 0)
	{
		this->m_hitPoint += amount;
		std::cout << "ClapTrap " << this->m_name << " added " << amount << " life points" \
		<< std::endl;
	}
	else
		std::cout << "ClapTrap " << this->m_name << " is out of energy or is dead" \
		<< std::endl;
}

int ClapTrap::getHitPoint()
{
	return (this->m_hitPoint);
}