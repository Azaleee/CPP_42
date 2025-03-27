//
// Created by mosmont on 3/6/25.
//

#ifndef CPP_42_SCAVTRAP_HPP
#define CPP_42_SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		~ScavTrap();
		ScavTrap	&operator=(const ScavTrap &other);

		void		attack(const std::string &target);
		void		guardGate(void);
};


#endif //CPP_42_SCAVTRAP_HPP
