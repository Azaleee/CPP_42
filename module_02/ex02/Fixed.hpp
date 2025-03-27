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
		~Fixed();

		Fixed 				&operator=(const Fixed &other);

		//Overload comparison operator
		bool				operator>(const Fixed &other) const;
		bool				operator<(const Fixed &other) const;
		bool				operator>=(const Fixed &other) const;
		bool				operator<=(const Fixed &other) const;
		bool				operator==(const Fixed &other) const;
		bool				operator!=(const Fixed &other) const;

		//Overload arithmetic operator
		Fixed				operator+(const Fixed &other) const;
		Fixed				operator-(const Fixed &other) const;
		Fixed				operator*(const Fixed &other) const;
		Fixed				operator/(const Fixed &other) const;

		Fixed				&operator++();
		Fixed				operator++(int);
		Fixed				&operator--();
		Fixed				operator--(int);

		static Fixed		min(Fixed &a, Fixed &b);
		static Fixed		min(const Fixed &a, const Fixed &b);

		static Fixed		max(Fixed &a, Fixed &b);
		static Fixed		max(const Fixed &a, const Fixed &b);

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