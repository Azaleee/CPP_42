//
// Created by mosmont on 3/6/25.
//

#ifndef CPP_42_CLAPTRAP_HPP
#define CPP_42_CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	protected:
		std::string		m_name;
		int				m_hitPoint;
		unsigned int	m_energyPoint;
		unsigned int	m_attackDamage;
	public:
		ClapTrap();
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap &other);
		~ClapTrap();
		ClapTrap		&operator=(const ClapTrap &other);

		void			attack(const std::string &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		int 			getHitPoint();
};


#endif //CPP_42_CLAPTRAP_HPP
