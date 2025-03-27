//
// Created by mosmont on 3/4/25.
//

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug()
{
	std::cout << "\033[34m[Debug] ...\033[0m" << std::endl;
}

void	Harl::error()
{
	std::cout << "\033[31m[Error] ...\033[0m" << std::endl;
}

void	Harl::info()
{
	std::cout << "[Info] ...\033[0m" << std::endl;
}

void	Harl::warning()
{
	std::cout << "\033[33m[Warning] ...\033[0m" << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string levels[4] = {
				"debug",
				"info",
				"warning",
				"error",
	};
	int i;
	for (i = 0; i < 4; i++)
	{
		if (level == levels[i])
			break ;
	}
	switch (i) {
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break;
		default:
			std::cout << "\033[30;41;1mSorry unknown level\033[0m" << std::endl;
	}

}