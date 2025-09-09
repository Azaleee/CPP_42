#include "PmergeMe.hpp"
#include <cmath>
#include <ctime>
#include <sys/stat.h>

static long elapsed_us(std::clock_t start, std::clock_t stop) {
    return static_cast<long>((stop - start) * 1000000.0 / CLOCKS_PER_SEC);
}

int main(int ac, char **av)
{
	PmergeMe pmm;
	std::vector<int> v;
	std::deque<int>  d;

	if (ac < 2) {
		std::cout << "Error" << std::endl;
		return 0;
	} else {
		try {
			v = pmm.parseArgs<std::vector<int> >(ac, av);
			d = pmm.parseArgs<std::deque<int> >(ac, av);
		} catch (const std::runtime_error &e) {
			std::cout << e.what() << std::endl;
			return 0;
		}
	}

	std::cout << "Before: ";
	pmm.displayContainer(d);
	std::cout << "" << std::endl;
	
	std::deque<int> result;
	std::clock_t t0 = std::clock();
	result = pmm.fordJohnsonSortDeque(d);
	std::clock_t t1 = std::clock();

	std::cout << "After:  ";
	pmm.displayContainer(result);
	std::cout << "" << std::endl;
	
	long us_vec = elapsed_us(t0, t1);
	std::cout << "Time to process a range of " << result.size()
          << " elements with std::deque : " << us_vec << " us\n";

	std::vector<int> resultV;
	t0 = std::clock();
	resultV = pmm.fordJohnsonSortVector(v);
	t1 = std::clock();

	us_vec = elapsed_us(t0, t1);
	std::cout << "Time to process a range of " << result.size()
          << " elements with std::vector : " << us_vec << " us\n";

	return 0;
}
