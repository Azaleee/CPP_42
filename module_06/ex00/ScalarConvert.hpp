#pragma once

#include <iostream>
# include <string>
# include <limits>
# include <iomanip>
# include <algorithm>
#include <cmath>

class ScalarConvert
{
	private:
		ScalarConvert();
		ScalarConvert(ScalarConvert const &);
		ScalarConvert &operator=(ScalarConvert const &);
		~ScalarConvert();
	public:
		static void convert(std::string const &literal);
};