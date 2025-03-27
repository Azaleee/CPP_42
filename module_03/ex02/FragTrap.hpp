//
// Created by mosmont on 3/10/25.
//

#ifndef CPP_42_FRAGTRAP_HPP
#define CPP_42_FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		~FragTrap();
		FragTrap	&operator=(const FragTrap &other);

		void		highFivesGuys(void);
};


#endif //CPP_42_FRAGTRAP_HPP
