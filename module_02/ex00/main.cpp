//
// Created by mosmont on 3/4/25.
//

#include "Fixed.hpp"

int	main(void)
{
	Fixed	a;
	std::cout << std::endl;
	Fixed	b(a);
	std::cout << std::endl;
	Fixed	c;
	std::cout << std::endl;

	b.setRawBits(10);
	std::cout << std::endl;
	c = b;
	std::cout << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << std::endl;
	return (0);
}