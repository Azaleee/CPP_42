//
// Created by mosmont on 2/25/25.
//

#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	Zombie	*herobrine;

	std::cout << "\n\n\033[30;46;1m/?\\\033[0m Zombie created by reference for use outside the newZombie function" << std::endl;
	herobrine = newZombie("herobrine");
	herobrine->announce();
	delete herobrine;
	std::cout << "\n\033[30;46;1m/?\\\033[0m Zombie temporarily created, announce function is only available in the randomChump function" << std::endl;
	randomChump("Temporary");
	return (0);
}