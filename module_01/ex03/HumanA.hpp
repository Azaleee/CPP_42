//
// Created by Macbook M1 pro on 26/02/2025.
//

#ifndef CPP_42_HUMANA_HPP
#define CPP_42_HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA {
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void		attack();
private:
	std::string name;
	Weapon		&type;
};

#endif //CPP_42_HUMANA_HPP
