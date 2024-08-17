#include "../inc/RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Program expects 2 arguments" << std::endl;
		return (1);
	}
	std::string equation(argv[1]);
	RPN rpn(equation);
	rpn.calculate();
}