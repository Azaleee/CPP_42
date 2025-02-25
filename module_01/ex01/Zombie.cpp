//
// Created by mosmont on 2/25/25.
//

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "\033[33;1m" << this->name << " joined the game\033[0m" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "\033[33;1m" << this->name << " left the game\033[0m" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": \033[32;1mBraiiiiiiinnnzzzZ...\033[0m" << std::endl;
}