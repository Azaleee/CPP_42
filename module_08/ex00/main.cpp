#include "easyfind.hpp"

int main(void)
{
	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(42);
	try
	{
		std::vector<int>::iterator it = easyfind(v, 20);
		std::cout << "Found at index " << std::distance(v.begin(), it) << std::endl;
	}
	catch(const NotFoundException &e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}