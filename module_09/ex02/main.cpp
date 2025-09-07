#include "PmergeMe.hpp"
#include <ctime>
#include <fstream>
#include <sys/stat.h>

static bool fileExists(const char* path) {
    struct stat st;
    return ::stat(path, &st) == 0 && S_ISREG(st.st_mode);
}

template <typename C>
void parseStreamInto(std::istream& in, C& out, bool allowDuplicates /*=false*/) {
    out.clear();
    std::set<int> seen;
    std::string tok;
    while (in >> tok) {
        int val;
        if (!parsePositiveIntToken(tok, val)) throw std::runtime_error("Error");
        if (!allowDuplicates) {
            if (!seen.insert(val).second) throw std::runtime_error("Error");
        }
        out.push_back(val);
    }
    if (out.empty()) throw std::runtime_error("Error");
}

static long elapsed_us(std::clock_t start, std::clock_t stop) {
    return static_cast<long>((stop - start) * 1000000.0 / CLOCKS_PER_SEC);
}


// static void printSeq(const char* label, const std::vector<size_t>& v)
// {
//     std::cout << label << " = [";
//     for (size_t i = 0; i < v.size(); ++i) {
//         std::cout << v[i] << (i+1 < v.size() ? ", " : "");
//     }
//     std::cout << "]\n";
// }

int main(int ac, char **av)
{
	PmergeMe pmm;
	std::vector<int> v;
	std::deque<int>  d;
	if (ac == 2 && fileExists(av[1])) {
    std::ifstream fin(av[1]);
    if (!fin) { std::cerr << "Error\n"; return 1; }
    parseStreamInto(fin, v, /*allowDuplicates=*/false);
    fin.clear(); fin.seekg(0);
    parseStreamInto(fin, d, /*allowDuplicates=*/false);
	} else {
		v = pmm.parseArgs<std::vector<int> >(ac, av);
		d = pmm.parseArgs<std::deque<int>  >(ac, av);
	}

	std::deque<int> result;
	std::clock_t t0 = std::clock();
	result = pmm.fordJohnsonSortDeque(d);
	std::clock_t t1 = std::clock();

	// pmm.displayDeque(result);

	long us_vec = elapsed_us(t0, t1);
	std::cout << "Time to process a range of " << result.size()
          << " elements with std::deque : " << us_vec << " us\n";

	std::vector<int> resultV;
	t0 = std::clock();
	resultV = pmm.fordJohnsonSortVector(v);
	t1 = std::clock();

	// pmm.displayVector(resultV);

	us_vec = elapsed_us(t0, t1);
	std::cout << "Time to process a range of " << result.size()
          << " elements with std::vector : " << us_vec << " us\n";

	return 0;
}