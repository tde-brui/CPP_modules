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

void BitcoinExchange::printExchangeRates()
{
	for (auto &it : _exchange_rates)
	{
		std::cout << it.first << ": " << it.second << std::endl;
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
	std::getline(file, line); // skip the first line
	while (std::getline(file, line))
		parseCvsLine(line);
}

void BitcoinExchange::parseCvsLine(std::string line)
{
	std::string date, rate;
	date = line.substr(0, line.find(','));
	rate = line.substr(line.find(',') + 1);
	_exchange_rates[date] = std::stod(rate);
}

void BitcoinExchange:: compareSecondDb(std::string filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		exit(1);
	}
	std::string line;
	while (std::getline(file, line))
		compareSecondDbLine(line);
}

void BitcoinExchange::compareSecondDbLine(std::string line)
{
	std::string date;
	double value = 0;
	if (line.find('|') == std::string::npos || line[0] == '|' || line[line.size() - 1] == '|')
	{
		std::cerr << "Error: invalid line format" << std::endl;
		return ;
	}
	date = line.substr(0, line.find('|') - 1);
	if (!checkDateFormat(date))
	{
		std::cerr << "Error: invalid date format. Please format like this: YYYY-MM-DD" << std::endl;
		return ;
	}
	try {
		value = std::stod(line.substr(line.find('|') + 1));
		if (value < 0 | value > 1000)
		{
			std::cerr << "Error: invalid value" << std::endl;
			return ;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: invalid value format" << std::endl;
		return ;
	}
	const double &exchangeRate = findClosestRate(date, _exchange_rates);
	const float product = value * exchangeRate;
	std::cout << date << " => " << value << " = " << product << std::endl;
}

bool BitcoinExchange::checkDateFormat(std::string date)
{
	if (date.size() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (date[i] < '0' || date[i] > '9')
			return false;
	}
	return true;
}

double BitcoinExchange::findClosestRate(std::string date, std::map<std::string, double> &db1)
{
	std::map<std::string, double>::iterator it = db1.upper_bound(date);
	if (it == db1.begin())
		return 0;
	it--;
	return it->second;
}


