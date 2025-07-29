#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string const &dataFile)
{
	try
	{
		BitcoinExchange::loadData(dataFile);
	} catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		this->data = other.data;
	return *this;
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	
	this->data = other.data;
}

void BitcoinExchange::loadData(std::string const &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open data file.");
	
	std::string line;
	if (!std::getline(file, line))
		throw std::runtime_error("Error: data file is empty.");

	while (std::getline(file, line))
	{
		std::size_t comma = line.find(',');
		if (comma == std::string::npos)
		{
			std::cerr << "Warning: bad line in " << filename << ": " << line << std::endl;
			continue; 
		}

		std::string date = line.substr(0, comma);
		std::string price = line.substr(comma + 1);

		char *endptr = NULL;
		float value = std::strtod(price.c_str(), &endptr);
		if (endptr == price.c_str() || *endptr != '\0')
		{
			std::cerr << "Warning: invalid price \"" << price << "\" on date " << date << "\n";
			continue;
		}
		data[date] = value;
	}
}

bool BitcoinExchange::validDate(std::string const &date)
{
	std::time_t now = std::time(NULL);
	std::tm* local = std::localtime(&now);
	int currentYear = local->tm_year + 1900;
	int currentMonth = local->tm_mon + 1;
	int currentDay = local->tm_mday; 
	
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12 || day < 1)
		return false;

	int daysInMonth[] = {31, 28, 31, 30, 31, 30,
						31, 31, 30, 31, 30, 31};

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		daysInMonth[1] = 29;

	if (day > daysInMonth[month - 1])
		return false;

	if (year > currentYear)
		return false;
	else if (year == currentYear && month > currentMonth)
		return false;
	else if (year == currentYear && month == currentMonth && day > currentDay)
		return false;

	return true;
}

float BitcoinExchange::getRateForDate(std::string const &date) const
{
	std::map<std::string, float>::const_iterator it = data.lower_bound(date);

	if (it != data.end() && it->first == date)
		return it->second;

	if (it == data.begin())
		throw std::out_of_range("Error: no rate available for this date");

	--it;
	return it->second;
}

void BitcoinExchange::processInputFile(std::string const &filename)
{
	std::ifstream in(filename.c_str());
	if (!in.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	if (!std::getline(in, line))
	{
		std::cerr << "Error: empty input file." << std::endl;
		return ;
	}

	while (std::getline(in, line))
	{
		std::size_t start = line.find_first_not_of(" \t");
		// Blank line
		if (start == std::string::npos)
			continue;
		std::size_t end = line.find_last_not_of(" \t");
		line = line.substr(start, end - start + 1);

		std::size_t bar = line.find('|');
		if (bar == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, bar);
		std::string value = line.substr(bar + 1);

		start = date.find_first_not_of(" \t");
		end = date.find_last_not_of(" \t");
		date = date.substr(start, end - start + 1);

		if (!validDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		char *endptr = NULL;
		double amount = std::strtod(value.c_str(), &endptr);
		if (endptr == value.c_str() || *endptr != '\0')
		{
			std::cerr << "Error: bad input => " << value << std::endl;
			continue;
		}
		if (amount < 0)
		{
			std::cerr << "Error: not a positive number" << std::endl;
			continue;
		}
		if (amount > 1000)
		{
			std::cerr << "Error: too large a number" << std::endl;
			continue;
		}

		float rate = BitcoinExchange::getRateForDate(date);
		if (rate < 0)
		{
			std::cerr << "Error: no rate available for this date" << std::endl;
			continue;
		}

		double result = rate * amount;
		std::cout
			<< date
			<< " => " << amount
			<< " = " << result
			<< std::endl;
	}
}
