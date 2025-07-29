#include "whatever.hpp"
#include <iostream>

int main(void)
{
	int a = 2, b = 42;
	std::cout << "a : " << a << " ; b : " << b << std::endl;
	::swap(a, b);
	std::cout << "a : " << a << " ; b : " << b << std::endl;

	std::cout << ::min(a, b) << std::endl;
	std::cout << ::max(a, b) << std::endl;

	std::string s1 = "test", s2 = "hello";
	std::cout << "s1 : " << s1 << " ; s2 : " << s2 << std::endl;
	::swap(s1, s2);
	std::cout << "s1 : " << s1 << " ; s2 : " << s2 << std::endl;

	std::cout << ::min(s1, s2) << std::endl;
	std::cout << ::max(s1, s2) << std::endl;
}