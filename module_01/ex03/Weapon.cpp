//
// Created by Macbook M1 pro on 26/02/2025.
//

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon()
{
	std::cout << "Destruction of the <<" << this->type << ">> weapon" << std::endl;
}

const std::string &Weapon::getType()
{
	return (type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}