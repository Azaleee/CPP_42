#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: btc <input_file>" << std::endl;
		return 1;
	}

	BitcoinExchange ex("data.csv");
	ex.processInputFile(av[1]);
	return 0;
}