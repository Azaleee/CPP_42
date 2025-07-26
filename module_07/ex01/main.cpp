#include "iter.hpp"
#include <iostream>

static void printInt(int &x)
{
	std::cout << x << std::endl;
}

int main(void)
{
	int arr[] = { 1, 2, 3, 4 };
	iter(arr, 4, printInt);
}