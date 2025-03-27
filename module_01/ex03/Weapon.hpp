//
// Created by Macbook M1 pro on 26/02/2025.
//

#ifndef CPP_42_WEAPON_HPP
#define CPP_42_WEAPON_HPP

#include <iostream>

class Weapon
{
public:
	Weapon(std::string type);
	~Weapon();

//	GETTER
	const std::string	&getType();
//	SETTER
	void				setType(std::string type);
private:
	std::string			type;
};


#endif //CPP_42_WEAPON_HPP
