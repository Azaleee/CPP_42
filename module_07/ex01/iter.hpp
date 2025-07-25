#pragma once

#include <string>

template<typename T, typename Func>
void iter(T *array, std::size_t length, Func f)
{
	if (!array) return ;
	for (std::size_t i = 0; i < length; i++)
		f(array[i]);
}