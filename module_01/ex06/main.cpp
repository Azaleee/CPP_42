#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		Harl	harl;

		harl.complain(av[1]);
	}
	else
	{
		std::cout << "\033[30;41;1mWrong arguments : Usage -> ./harlFilter <complain>\033[0m" << std::endl;
	}
	return (0);
}