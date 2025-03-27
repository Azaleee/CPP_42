//
// Created by mosmont on 2/25/25.
//

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*horde = new Zombie[N];

	for (int i = 0; i < N; ++i)
		horde[i].setName(name);
	return (horde);
}