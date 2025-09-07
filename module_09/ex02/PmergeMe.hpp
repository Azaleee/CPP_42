#pragma once

#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <string>
#include <sys/time.h>
#include <climits>
#include <cerrno>
#include <cstdlib>

class PmergeMe
{
	public:
		PmergeMe() {};
		~PmergeMe() {};

		void displayVectorPairs(const std::vector<std::pair<int, int> > &pairs);
		void displayVector(const std::vector<int> &input);
		void displayDeque(const std::deque<int> &input);

		template <typename C>
		C fordJohnsonSortGeneric(C input);

		std::vector<int> fordJohnsonSortVector(const std::vector<int> &input);
		std::deque<int> fordJohnsonSortDeque (const std::deque<int> &input);

		template <typename C>
		C parseArgs(int ac, char **av)
		{
			C out;
			parseArgvInto(ac, av, out);
			return out;
		}
	private:
		void sortPairsByBig(std::vector<std::pair<int, int> > &pairs);
		void generateJacobSequence(size_t n, std::vector<size_t> &J);
		void generateJacobInsertionOrder(size_t n, std::vector<size_t> &order);

		template <typename C>
		void groupIntoPairs(const C &input, std::vector<std::pair<int, int> > &pairs, bool &hasOddElement, int &oddElement);

		template <typename C>
		void buildMainFromPairs(const std::vector<std::pair<int, int> > &pairs, C &main);

		template <typename C>
		void insertFirstSmall(C &main, const std::pair<int, int> &firstPair);

		template <typename C>
		void insertSmallBounded(C &main, int small, int big);

		template <typename C>
		void insertSmallsWithOrder(C &main, const std::vector< std::pair<int,int> >& pairs, const std::vector<size_t>& order);

		bool parsePositiveIntToken(const std::string& tok, int &out);

		template <typename C>
		void parseArgvInto(int ac, char **av, C& out)
		{
			out.clear();

			for (int i = 1; i < ac; i++)
			{
				int val;
				if (!parsePositiveIntToken(std::string(av[i]), val))
					throw std::runtime_error("Error");
				out.push_back(val);
			}

			if (out.empty())
				throw std::runtime_error("Error");
		}
};

#include "PmergeMe.tpp"