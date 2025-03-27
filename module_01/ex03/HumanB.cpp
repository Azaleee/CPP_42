//
// Created by Macbook M1 pro on 26/02/2025.
//

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = nullptr;
}

HumanB::~HumanB()
{
	std::cout << this->name << " died of memory destruction" << std::endl;
}


void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack()
{
	if (weapon == nullptr)
		std::cout << "It's hard to fight without a weapon" << std::endl;
	else
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}