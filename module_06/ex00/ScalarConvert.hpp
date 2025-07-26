#pragma once

#include <iostream>
# include <string>
# include <climits>
# include <iomanip>
# include <algorithm>

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