//
// Created by Macbook M1 pro on 28/02/2025.
//

#include "ReplaceFile.hpp"

std::string	replaceLine(std::string line, const std::string &s1, const std::string &s2)
{
	size_t	pos = 0;

	// static const size_t npos = -1;
	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
		pos += s2.length();
	}
	return (line);
}

void	replaceFile(const char **av)
{
	std::ifstream input(av[1]);
	if (!input.is_open())
	{
		std::cout << "Error with input file" << std::endl;
		return ;
	}

	if (std::string(av[2]).empty())
	{
		std::cout << "s1 is empty" << std::endl;
		if (input)
			input.close();
		return ;
	}

	std::string fileName = av[1];
	fileName.append(".replace");
	std::ofstream output(fileName.c_str());
	if (!output.is_open())
	{
		std::cout << "Error with output file" << std::endl;
		if (input)
			input.close();
		return ;
	}

	std::string actualLine;
	std::string s1 = av[2];
	std::string s2 = av[3];

	while (getline(input, actualLine))
		output << replaceLine(actualLine, s1, s2) << std::endl;

	input.close();
	output.close();
}