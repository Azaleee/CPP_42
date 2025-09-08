#include "PmergeMe.hpp"

bool PmergeMe::parsePositiveIntToken(const std::string& tok, int &out)
{
	if (tok.empty()) return false;

	for (size_t i = 0; i < tok.size(); i++)
		if (tok[i] == ' ' || tok[i] == '\t' || tok[i] == '\n') return false;

	if (tok[0] == '-') return false;

	char *endptr = 0;
	errno = 0;
	long val = std::strtol(tok.c_str(), &endptr, 10);

	if (errno == ERANGE || endptr == tok.c_str() || *endptr != '\0') return false;

	if (val <= 0 || val > INT_MAX) return false;

	out = static_cast<int>(val);
	return true;
}

void PmergeMe::generateJacobSequence(size_t n, std::vector<size_t> &J)
{
	J.clear();
	J.push_back(0);
	J.push_back(1);

	while (J.back() < n)
	{
		size_t k = J.size();
		size_t next = J[k - 1] + 2 * J[k - 2];
		J.push_back(next);
	}
}

void PmergeMe::generateJacobInsertionOrder(size_t n, std::vector<size_t> &order)
{
	order.clear();
	if (n <= 1) return;

	std::vector<size_t> J;
	generateJacobSequence(n, J);

	// (last, end] > last, <= end
	size_t last = 1;
	for (size_t k = 2; last < (n - 1) && k < J.size(); ++k)
	{
		size_t end = J[k];
		if (end > (n - 1)) end = (n - 1);

		for (size_t i = end; i > last; i--)
			order.push_back(i);
		
		last = end;
	}

	order.push_back(1);
}

bool compareBig(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
	return a.first < b.first;
}

void PmergeMe::sortPairsByBig(std::vector<std::pair<int, int> > &pairs)
{
	std::sort(pairs.begin(), pairs.end(), compareBig);
}

std::vector<int> PmergeMe::fordJohnsonSortVector(const std::vector<int>& input) {
    return fordJohnsonSortGeneric(input);
}
std::deque<int> PmergeMe::fordJohnsonSortDeque(const std::deque<int>& input) {
    return fordJohnsonSortGeneric(input);
}
