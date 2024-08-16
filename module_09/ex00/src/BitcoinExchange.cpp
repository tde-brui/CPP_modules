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

void BitcoinExchange:: parseSecondDb(std::string filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		exit(1);
	}
	std::string line;
	while (std::getline(file, line))
		parseSecondDbLine(line);
}

void BitcoinExchange::parseSecondDbLine(std::string line)
{
	//std::cout << line << std::endl;
	std::string date, value;
	if (line.find('|') == std::string::npos)
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
	value = line.substr(line.find('|') + 1);
	_second_db[date].push_back(std::stod(value));
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
	{
		std::cerr << "Error: no date lower than " << date << " found in database" <<  std::endl;
		exit(1);
	}
	it--;
	return it->second;
}
void BitcoinExchange::CompareDatabases()
{
	std::map<std::string, double> first_db = _exchange_rates;
	std::map<std::string, std::vector<double> >  second_db = _second_db;



	for (auto &it : second_db)
	{
		const std::string &date = it.first;
		for (auto &value : it.second)
		{
			const double &exchangeRate = findClosestRate(date, first_db);
			const float product = value * exchangeRate;
			std::cout << date << " => " << value << " = " << product << std::endl;
		}
	}
}

