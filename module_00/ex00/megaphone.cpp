#include <iostream>

int main (int ac, char **av)
{
	int i;
	int j;

	i = 0;
	if (ac > 1)
	{
		while (av[++i])
		{
			j = -1;
			while (av[i][++j])
				std::cout << (char)std::toupper(av[i][j]);
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << "\n";
	return (0);
}