//
// Created by mosmont on 3/4/25.
//

#ifndef CPP_42_FIXED_HPP
#define CPP_42_FIXED_HPP

#include <iostream>

class Fixed {
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed &other);

		int 				getRawBits(void) const;
		void				setRawBits(int const raw);
	private:
		int					value;
		static const int	bits = 8;
};

#endif //CPP_42_FIXED_HPP
