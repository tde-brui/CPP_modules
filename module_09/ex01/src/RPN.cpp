#include "../inc/RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(std::string equation)
{
	this->_equation = equation;
}

RPN::~RPN()
{
}

bool RPN::isOperator(std::string token)
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

void RPN::compressStack(char operatorChar)
{
	// dont forget to pop each element.
	if (_stack.size() < 2)
	{
		std::cerr << "Error: Not enough operands on stack" << std::endl;
		exit(1);
	}
	int top1 = _stack.top(); _stack.pop();
	int top2 = _stack.top(); _stack.pop();
	int result = 0;

	switch (operatorChar)
	{
		case '+':
			result = top1 + top2;
			break ;
		case '-':
			result = top2 - top1;
			break ;
		case '*':
			result = top1 * top2;
			break ;
		case '/':
			if (top2 == 0)
			{
				std::cerr << "Error: attempting division by 0" << std::endl;
				exit(1);
			}
			result = top1 / top2;
			break ;
		default: 
			std::cerr << "invalid operator" << std::endl;
			exit(1);
	}
	std::cout << "Result: " << result << std::endl;
	_stack.push(result);
}

void RPN::calculate()
{
	std::istringstream iss(_equation);
	std::string token;
	while (iss >> token)
	{
		if (isOperator(token))
			compressStack(token[0]);
		else
		{
			try
			{
				int value = std::stoi(token);
				_stack.push(value);
			}
			catch (std::exception &e)
			{
				std::cerr << "invalid value inside equation" << std::endl;
				exit(1);
			}
		}
	}
	if (_stack.size() == 1)
		std::cout << "Result: " << _stack.top() << std::endl;
	else
	{
		std::cerr << "Error: Invalid equation" << std::endl;
		exit(1);
	}
}