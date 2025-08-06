#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stack>

#define NB_OP 4

class RPN
{
	private:
		std::stack<int> tokens;
		RPN(RPN const &) {};
		RPN &operator=(RPN const &) { return *this; };
		void validateToken(std::string const &token);

		void handleAdd();
		void handleSub();
		void handleTime();
		void handleDivide();

		int pop();
	public:
		RPN() {};
		~RPN() {};
		void evaluate(std::string const &expression);

		struct Error : std::runtime_error
		{
			Error(char const *msg = "Error") : std::runtime_error(msg) {};
		};
};