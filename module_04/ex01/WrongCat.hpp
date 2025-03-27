//
// Created by mosmont on 3/10/25.
//

#ifndef CPP_42_WRONGCAT_HPP
#define CPP_42_WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &other);
		~WrongCat();
		WrongCat		operator=(const WrongCat &other);

		void	makeSound(void) const;
};

#endif //CPP_42_WRONGCAT_HPP
