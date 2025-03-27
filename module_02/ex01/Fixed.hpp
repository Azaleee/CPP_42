//
// Created by mosmont on 3/4/25.
//

#ifndef CPP_42_FIXED_HPP
#define CPP_42_FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	public:
		Fixed();
		Fixed(int const value);
		Fixed(float const value);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();

		float 				toFloat(void) const;
		int 				toInt(void) const;
		int 				getRawBits(void) const;
		void				setRawBits(int const raw);
	private:
		int					_value;
		static const int	_bits = 8;
};

std::ostream		&operator<<(std::ostream &out, Fixed const &fixed);

#endif //CPP_42_FIXED_HPP