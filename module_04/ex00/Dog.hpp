//
// Created by mosmont on 3/10/25.
//

#ifndef CPP_42_DOG_HPP
#define CPP_42_DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &other);
		~Dog();
		Dog		operator=(const Dog &other);

		void	makeSound(void) const;
};


#endif //CPP_42_DOG_HPP
