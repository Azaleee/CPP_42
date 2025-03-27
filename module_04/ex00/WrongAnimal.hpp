//
// Created by mosmont on 3/10/25.
//

#ifndef CPP_42_WRONGANIMAL_HPP
#define CPP_42_WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal			&operator=(const WrongAnimal &other);

		void			makeSound(void) const;
		std::string 	getType(void) const;
	protected:
		std::string		m_type;
};


#endif //CPP_42_WRONGANIMAL_HPP
