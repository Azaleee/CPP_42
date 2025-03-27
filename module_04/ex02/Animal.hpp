//
// Created by mosmont on 3/10/25.
//

#ifndef CPP_42_ANIMAL_HPP
#define CPP_42_ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);

		virtual	void	makeSound(void) const = 0;
		std::string 	getType(void) const;
	protected:
		std::string		m_type;
};


#endif //CPP_42_ANIMAL_HPP
