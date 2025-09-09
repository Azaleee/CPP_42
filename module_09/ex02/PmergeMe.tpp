template <typename C>
void PmergeMe::displayContainer(const C &input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		std::cout << input[i] << " ";
	}
	
}

template <typename C>
void PmergeMe::buildMainFromPairs(const std::vector<std::pair<int, int> > &pairs, C &main)
{
	main.clear();
	for (size_t i = 0; i < pairs.size(); i++)
		main.push_back(pairs[i].first);
}

template <typename C>
void PmergeMe::insertFirstSmall(C &main, const std::pair<int, int> &firstPair)
{
	int small = firstPair.second;
	int big = firstPair.first;

	typename C::iterator itBig = std::find(main.begin(), main.end(), big);

	typename C::iterator pos = std::lower_bound(main.begin(), itBig, small);
	main.insert(pos, small);
}

template <typename C>
void PmergeMe::insertSmallBounded(C &main, int small, int big)
{
	typename C::iterator itBig = std::lower_bound(main.begin(), main.end(), big);
	typename C::iterator pos = std::lower_bound(main.begin(), itBig, small);
	main.insert(pos, small);
}

template <typename C>
void PmergeMe::insertSmallsWithOrder(C &main, const std::vector< std::pair<int,int> >& pairs, const std::vector<size_t>& order)
{
	for (size_t i = 0; i < order.size(); ++i)
	{
		size_t k = order[i];
		insertSmallBounded(main, pairs[k].second, pairs[k].first);
	}
}

template <typename C>
C PmergeMe::fordJohnsonSortGeneric(C input)
{
	if (input.size() <= 1) return input;

	std::vector<std::pair<int, int> > pairs;
	bool hasOddElement;
	int oddElement;

	groupIntoPairs(input, pairs, hasOddElement, oddElement);

	sortPairsByBig(pairs);

	C main;
	buildMainFromPairs(pairs, main);

	insertFirstSmall(main, pairs[0]);

	std::vector<size_t> order;
	generateJacobInsertionOrder(pairs.size(), order);

	insertSmallsWithOrder(main, pairs, order);

	if (hasOddElement)
	{
		typename C::iterator pos = std::lower_bound(main.begin(), main.end(), oddElement);
        main.insert(pos, oddElement);
	}

	return main;
}

template <typename C>
void PmergeMe::groupIntoPairs(const C &input, std::vector<std::pair<int, int> > &pairs, bool &hasOddElement, int &oddElement)
{
	pairs.clear();
	hasOddElement = (input.size() % 2 == 1);
	if (hasOddElement)
	{
		oddElement = input[input.size() - 1];
	}

	for (size_t i = 0; i < input.size() - (hasOddElement ? 1 : 0); i += 2)
	{
		int first = input[i];
		int second = input[i + 1];

		if (first <= second)
		{
			pairs.push_back(std::make_pair(second, first));
		}
		else
		{
			pairs.push_back(std::make_pair(first, second));
		}
	}
}

template <typename C>
C PmergeMe::parseArgs(int ac, char **av)
{
	C out;
	parseArgvInto(ac, av, out);
	return out;
}


template <typename C>
void PmergeMe::parseArgvInto(int ac, char **av, C& out)
{
	out.clear();

	for (int i = 1; i < ac; i++)
	{
		int val;
		if (!parsePositiveIntToken(std::string(av[i]), val))
			throw std::runtime_error("Error with parsing");
		out.push_back(val);
	}

	if (out.empty())
		throw std::runtime_error("Error container is empty");
}
