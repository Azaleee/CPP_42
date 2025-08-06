#include "RPN.hpp"

void RPN::validateToken(std::string const &token)
{
	if (token.length() != 1 || !isdigit(token[0]))
		throw RPN::Error("Error: Invalid token");
	else
		tokens.push(static_cast<int>(token[0] - '0'));
}

void RPN::evaluate(std::string const &expression)
{
	std::istringstream iss(expression);
	std::string token;

	static const std::string ops[NB_OP] = { "+", "-", "*", "/" };
	typedef void (RPN::*OpFunc)();
	static const OpFunc funcs[NB_OP] = {
		&RPN::handleAdd,
		&RPN::handleSub,
		&RPN::handleTime,
		&RPN::handleDivide
	};
	while (iss >> token)
	{
		bool matched = false;

		for (int i = 0; i < NB_OP; i++)
		{
			if (token == ops[i])
			{
				(this->*funcs[i])();
				matched = true;
				break ;
			}
		}

		if (!matched)
		{
			validateToken(token);
		}
	}

	if (tokens.size() == 1) std::cout << tokens.top() << std::endl;
	else throw RPN::Error("Error: Invalid token");
}


void RPN::handleAdd()
{
	int a = RPN::pop(), b = RPN::pop();
	tokens.push(b + a);
}

void RPN::handleSub()
{
	int a = RPN::pop(), b = RPN::pop();
	tokens.push(b - a);
}

void RPN::handleTime()
{
	int a = RPN::pop(), b = RPN::pop();
	tokens.push(b * a);
}

void RPN::handleDivide()
{
	int a = RPN::pop(), b = RPN::pop();
	if (a == 0) throw Error("Error: Div by 0 is impossible");
	tokens.push(b / a);
}

int RPN::pop()
{
	if (tokens.empty()) throw Error("Error: Stack is empty");
	int v = tokens.top();
	tokens.pop();
	return v;
}