#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _exchange_rates;
		std::map<std::string, std::vector<double> > _second_db;
		std::string _filename;


	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &bitcoinexchange);
		BitcoinExchange &operator=(const BitcoinExchange &bitcoinexchange);
		double getRate(std::string currency);

		void parseCvs();
		void parseCvsLine(std::string line);
		void parseSecondDb(std::string line);
		bool checkDateFormat(std::string date);
		void parseSecondDbLine(std::string line);

		void printExchangeRates();
		void printConversion(std::string currency, double amount);

		void CompareDatabases();
		double findClosestRate(std::string date, std::map<std::string, double> &db1);

};