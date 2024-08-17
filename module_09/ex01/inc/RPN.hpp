#include <iostream>
#include <stack>
#include <sstream>

class RPN
{
	public:
		RPN();
		RPN(std::string equation);
		RPN(const RPN &rpn);
		RPN &operator=(const RPN &rpn);
		~RPN();
		void calculate();
		bool isOperator(std::string token);
		void compressStack(char operatorChar);

	private:
		std::string _equation;
		std::stack<int> _stack;
};