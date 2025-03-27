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
	void (Harl::*functions[4])() = {
			&Harl::debug,
			&Harl::error,
			&Harl::info,
			&Harl::warning
	};
	std::string levels[4] = {
			"debug",
			"error",
			"info",
			"warning"
	};
	bool has_found = false;
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			has_found = true;
		}
	}
	if (!has_found)
		std::cout << "\033[30;41;1mSorry unknown level\033[0m" << std::endl;
}