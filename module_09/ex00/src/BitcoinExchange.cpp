#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
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

void BitcoinExchange::Parseline(std::string line)
{
	std::string key;
	double value;
	std::stringstream ss(line);
	ss >> key >> value;
	_exchange_rates[key] = value;
}

