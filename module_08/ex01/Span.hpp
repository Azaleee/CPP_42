#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	private:
		unsigned int _N;
		std::vector<int> _tab;
	public:
		Span();
		Span(unsigned int N);
		~Span();

		void addNumber(int number);
		int longestSpan(void) const;
		int shortestSpan(void) const;
};