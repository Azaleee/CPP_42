//
// Created by mosmont on 3/13/25.
//

#ifndef CPP_42_ICHARACTER_HPP
#define CPP_42_ICHARACTER_HPP

#include "AMateria.hpp"

class ICharacter
{
	public:
		virtual ~ICharacter() {}

		virtual std::string const	&getName() const = 0;
		virtual void 				equip(AMateria* m) = 0;
		virtual void 				unequip(int idx) = 0;
		virtual void 				use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter
{
	private:
		std::string	name;
		AMateria*	inventory[4];

	public:
		Character();
		Character(std::string const &name);
		Character(const Character &other);
		Character &operator=(const Character &other);
		~Character();


};

#endif //CPP_42_ICHARACTER_HPP
