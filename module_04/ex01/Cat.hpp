//
// Created by mosmont on 3/10/25.
//

#ifndef CPP_42_CAT_HPP
#define CPP_42_CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &other);
		~Cat();
		Cat	&operator=(const Cat &other);

		void		makeSound(void) const;
		void		setIdea(int i, std::string str);
		std::string getIdea(int i);
	private:
		Brain*		brain;
};


#endif //CPP_42_CAT_HPP
