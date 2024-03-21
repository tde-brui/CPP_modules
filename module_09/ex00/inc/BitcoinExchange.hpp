#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _exchange_rates;
		std::map<std::string, double> _wallet;
		std::string _filename;


	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &bitcoinexchange);
		BitcoinExchange &operator=(const BitcoinExchange &bitcoinexchange);
		void Parseline(std::string line);

};