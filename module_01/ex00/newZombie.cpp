//
// Created by mosmont on 2/25/25.
//

#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie	*zombie = new Zombie(name);
	return (zombie);
}