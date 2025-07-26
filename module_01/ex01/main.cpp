//
// Created by mosmont on 2/25/25.
//

#include "Zombie.hpp"
#include <iostream>

int	main(void)
{

	Zombie	*horde;

	std::cout << "\033[30;46;1m/?\\\033[0m Zombie horde created by reference for use outside the zombieHorde function" << std::endl;
	horde = zombieHorde(5, "Bizon");
	for (int i = 0; i < 5; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}