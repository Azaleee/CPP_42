//
// Created by mosmont on 3/13/25.
//

#ifndef CPP_42_AMATERIA_HPP
#define CPP_42_AMATERIA_HPP

#include <iostream>
#include <string>

class AMateria
{
	protected:
		std::string			m_type;

	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &other);
		virtual ~AMateria();

		std::string const 	&getTYpe() const;

		virtual AMateria* 	clone() const = 0;
		virtual void 		use(ICharacter& target);
};


#endif //CPP_42_AMATERIA_HPP
