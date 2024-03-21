#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	first_line_skipped = false;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bitcoinexchange)
{
	*this = bitcoinexchange;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &bitcoinexchange)
{
	(void)bitcoinexchange;
	return *this;
}

void BitcoinExchange::printExchangeRates()
{
	for (auto &it : _exchange_rates)
	{
		std::cout << it.first << ": " << it.second << std::endl;
	}
}

void BitcoinExchange::parseCvsLine(std::string line)
{
	std::istringstream iss(line);
	std::string date, rate;
	std::getline(iss, date, ',');
	std::getline(iss, rate);
	_exchange_rates[date] = std::stod(rate);
}

void BitcoinExchange::CompareDatabases(char *filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		exit(1);
	}
	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string date, amount;
		std::getline(iss, date, ' ');
		
	}
}
void BitcoinExchange::parseCvs()
{
	std::ifstream file("data.csv");
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		exit(1);
	}
	std::string line;
	while (std::getline(file, line))
	{
		if (!first_line_skipped)
		{
			first_line_skipped = true;
			continue;
		}
		parseCvsLine(line);
	}
}
