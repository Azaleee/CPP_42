//
// Created by mosmont on 2/25/25.
//

#include <iostream>
#include <string>

#ifndef CPP_42_ZOMBIE_HPP
#define CPP_42_ZOMBIE_HPP

class Zombie
{
public:
	Zombie();
	~Zombie();

	void	announce(void);

//	SETTER
	void	setName(std::string name);
private:
	std::string	name;
};

Zombie		*zombieHorde(int N, std::string name);

#endif //CPP_42_ZOMBIE_HPP
