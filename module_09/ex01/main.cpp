#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./RPN \"expression\"" << std::endl;
		return 1;
	}

	try
	{
		RPN rpn;
		rpn.evaluate(av[1]);
	}
	catch(const RPN::Error &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}
