#include "whatever.hpp"
#include <iostream>

int main(void)
{
	int a = 2, b = 42;
	::swap(a, b);
	std::cout << "a : " << a << " ; b : " << b << std::endl;

	std::cout << ::min(a, b) << std::endl;
	std::cout << ::max(a, b) << std::endl;

	std::string s1 = "test", s2 = "hello";
	::swap(s1, s2);
	std::cout << "s1 : " << s1 << " ; s2 : " << s2 << std::endl;
}