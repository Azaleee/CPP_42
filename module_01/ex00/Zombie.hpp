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
	Zombie(std::string name);
	~Zombie();

	void	announce(void);
private:
	std::string	name;
};

Zombie		*newZombie(std::string name);
void		randomChump(std::string name);

#endif //CPP_42_ZOMBIE_HPP
