//
// Created by Macbook M1 pro on 26/02/2025.
//

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), type(weapon) {}

HumanA::~HumanA()
{
	std::cout << this->name << " died of memory destruction" << std::endl;
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their " << type.getType() << std::endl;
}