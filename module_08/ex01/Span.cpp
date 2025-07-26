#include "Span.hpp"

Span::Span() : _N(0) {};

Span::Span(unsigned int N) : _N(N) {};

Span::~Span() {};

void Span::addNumber(int number)
{
	if (_tab.size() >= _N)
		throw std::out_of_range("Span full");
	_tab.push_back(number);
}

int Span::longestSpan(void) const
{
	if (_tab.size() < 2)
		throw std::logic_error("Not enough elements");
	int min = *std::min_element(_tab.begin(), _tab.end());
	int max = *std::max_element(_tab.begin(), _tab.end());

	return max - min;
}

int Span::shortestSpan(void) const
{
	if (_tab.size() < 2)
		throw std::logic_error("Not enough elements");
	std::vector<int> tmp = _tab;
	std::sort(tmp.begin(), tmp.end());
	int best = tmp[1] - tmp[0];
	for (std::size_t i = 2; i < tmp.size(); ++i)
	{
		int gap = tmp[i] - tmp[i - 1];
		if (gap < best)
			best = gap;
	}
	return best;
}