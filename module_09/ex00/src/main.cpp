#include "../inc/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./bitcoin_exchange filename" << std::endl;
		return 1;
	}
	BitcoinExchange exchange(argv[1]);
	return 0;	
}