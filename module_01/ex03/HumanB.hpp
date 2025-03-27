//
// Created by Macbook M1 pro on 26/02/2025.
//

#ifndef CPP_42_HUMANB_HPP
#define CPP_42_HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB {
public:
	HumanB(std::string name);
	~HumanB();

	void		setWeapon(Weapon &weapon);
	void		attack();
private:
	std::string	name;
	Weapon		*weapon;
};


#endif //CPP_42_HUMANB_HPP
