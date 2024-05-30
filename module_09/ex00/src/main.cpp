#include "../inc/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	BitcoinExchange bitcoinexchange;
	if (argc != 2)
	{
		std::cout << "Usage: ./bitcoin_exchange filename" << std::endl;
		return 1;
	}
	bitcoinexchange.parseCvs();
	bitcoinexchange.CompareDatabases(argv[1]);
}