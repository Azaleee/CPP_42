#include <iostream>
#include <exception>
#include <iterator>
#include <vector>
#include <algorithm>

class NotFoundException : public std::exception
{
	public:
		virtual char const *what() const throw()
		{
			return "Not found";
		};
};

template<typename T>
typename T::iterator easyfind(T &in, int i)
{
	typename T::iterator it;
	it = find(in.begin(), in.end(), i);
	if (it == in.end()) { throw NotFoundException(); };
	return it;
}
