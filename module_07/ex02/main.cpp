#include "Array.hpp"

int main(void)
{
	Array<int> x(5);
	x[2] = 42;
	std::cout << x[2] << std::endl;

	Array<int> y = x;
	std::cout << y[2] << std::endl;

	std::cout << y.size() << std::endl;

	try
	{
		y[42] = 45;
	}
	catch (const std::exception &e) { std::cout << e.what() << std::endl; };
};