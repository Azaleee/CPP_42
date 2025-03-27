//
// Created by Macbook M1 pro on 26/02/2025.
//

#include <iostream>

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "Address of initial string variable -> \033[1;32;49m" << &string << "\033[0;39;49m" << std::endl;
	std::cout << "Address of string variable -> \033[1;32;49m" << stringPTR << "\033[0;39;49m" << std::endl;
	std::cout << "Address of string reference -> \033[1;32;49m" << &stringREF << "\033[0;39;49m" << std::endl;
	std::cout << std::endl;
	std::cout << "Value of the string variable -> \033[1;32;49m" << string << "\033[0;39;49m" << std::endl;
	std::cout << "Value pointed to by stringPTR -> \033[1;32;49m" << *stringPTR << "\033[0;39;49m" << std::endl;
	std::cout << "Value pointed to by stringREF -> \033[1;32;49m" << stringREF << "\033[0;39;49m" << std::endl;
	return (0);
}