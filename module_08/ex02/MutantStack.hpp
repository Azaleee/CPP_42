#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() {}
		MutantStack(Mutant stack &other) : std::stack<T>(other) {}
		
};