//
// Created by mosmont on 3/13/25.
//

#ifndef CPP_42_ICE_HPP
#define CPP_42_ICE_HPP

#include "AMateria.hpp"
#include <iostream>

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &other);
		Ice &operator=(const Ice &other);
		~Ice();

		AMateria*	clone() const;
		void 		use(ICharacter& target);
};


#endif //CPP_42_ICE_HPP
