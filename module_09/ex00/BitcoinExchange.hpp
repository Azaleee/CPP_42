#pragma once

#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

class BitcoinExchange
{
	private:
		BitcoinExchange();
		std::map<std::string, float> data;
		void loadData(std::string const &filename);
		bool validDate(std::string const &date);
		float getRateForDate(std::string const &date) const;
	public:
		BitcoinExchange(std::string const &dataFile);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& other);
		BitcoinExchange(const BitcoinExchange& copy);
		void processInputFile(std::string const &filename);

};