//
// Created by Macbook M1 pro on 28/02/2025.
//

#include <iostream>
#include "ReplaceFile.hpp"

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		replaceFile(av);
	}
	else
	{
		std::cout << "Error usage : ./file <file_name> <s1> <s2>" << std::endl;
	}
	return (0);
}