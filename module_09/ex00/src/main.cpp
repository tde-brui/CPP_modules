#include "../inc/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	BitcoinExchange bitcoinexchange;
	if (argc != 2)
	{
		std::cout << "Usage: ./bitcoin_exchange filename" << std::endl;
		return 1;
	}
	bitcoinexchange.parseCvs();
	bitcoinexchange.parseSecondDb(argv[1]);
	bitcoinexchange.CompareDatabases();
}