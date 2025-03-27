//
// Created by mosmont on 3/10/25.
//

#ifndef CPP_42_CAT_HPP
#define CPP_42_CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &other);
		~Cat();
		Cat		operator=(const Cat &other);

		void	makeSound(void) const;
};


#endif //CPP_42_CAT_HPP
