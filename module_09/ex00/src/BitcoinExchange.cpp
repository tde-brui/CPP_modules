#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const std::string &filename) : _filename(filename)
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

