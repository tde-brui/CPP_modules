#include "../inc/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	BitcoinExchange bitcoinexchange;
	if (argc != 2)
	{
		std::cout << "Usage: ./bitcoin_exchange filename" << std::endl;
		return 1;
	}
	std::ifstream file(argv[1]);
	if (!file.is_open())
	{
		std::cout << "Error: file open" << std::endl;
		return 1;
	}
	std::string line;
	while (std::getline(file, line))
	{
		bitcoinexchange.Parseline(line);
	}
	file.close();
	for (const auto &i : bitcoinexchange._exchange_rates)
	{
		std::cout << i.first << " " << i.second << std::endl;
	}
}