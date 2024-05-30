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
		bool first_line_skipped;


	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &bitcoinexchange);
		BitcoinExchange &operator=(const BitcoinExchange &bitcoinexchange);
		double getRate(std::string currency);
		void parseCvs();
		void parseCvsLine(std::string line);
		void printExchangeRates();
		void printConversion(std::string currency, double amount);

		void CompareDatabases(char *filename);

};