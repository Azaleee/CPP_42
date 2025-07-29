#include "ScalarConvert.hpp"

ScalarConvert::ScalarConvert() {}

ScalarConvert::ScalarConvert(ScalarConvert const &) {};

ScalarConvert &ScalarConvert::operator=(ScalarConvert const &) {return *this;};

ScalarConvert::~ScalarConvert() {};

void ScalarConvert::convert(std::string const &literal) {
	double d = 0.0; // Input double for universal
	
	bool isPseudo = (literal == "nan" || literal == "nanf"
				|| literal == "+inf"|| literal == "+inff"
				|| literal == "-inf"|| literal == "-inff");

	if (isPseudo) {
		if (literal[literal.size() - 1] == 'f')
			d = (literal[0] == '-') ? -std::numeric_limits<double>::infinity() : std::numeric_limits<double>::infinity();
		else
			d = std::numeric_limits<double>::quiet_NaN();
		if (literal == "nanf") d = std::numeric_limits<double>::quiet_NaN();
	}
	else if (literal.size() == 1 && !std::isdigit(literal[0])) {
		d = static_cast<double>(literal[0]);
	}
	else if (literal.find('.') != std::string::npos) {
		std::string num = literal;
		if (literal[literal.size() - 1] == 'f') {
			num = literal.substr(0, literal.size() - 1);
		}
		d = std::strtod(num.c_str(), 0);
	}
	else {
		long l = std::strtol(literal.c_str(), 0, 10);
		d = static_cast<double>(l);
	}

	float f = static_cast<float>(d);
	long i = static_cast<long>(d);
	char c = static_cast<char>(d);

	std::cout << "char: ";
	if (std::isnan(d) || d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max()) {
		std::cout << "impossible\n";
	} else if (!std::isprint(c)) {
		std::cout << "Non displayable\n";
	} else {
		std::cout << "'" << c << "'\n";
	}

	std::cout << "int: ";
	if (std::isnan(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) {
		std::cout << "impossible\n";
	} else {
		std::cout << i << "\n";
	}

	std::cout << "float: ";
	if (std::isnan(f)) {
		std::cout << "nanf\n";
	} else if (std::isinf(f)) {
		std::cout << (f < 0 ? "-inff\n" : "+inff\n");
	} else {
		std::cout << std::fixed << std::setprecision(1) << f << "f\n";
	}

	std::cout << "double: ";
	if (std::isnan(d)) {
		std::cout << "nan\n";
	} else if (std::isinf(d)) {
		std::cout << (d < 0 ? "-inf\n" : "+inf\n");
	} else {
		std::cout << std::fixed << std::setprecision(1) << d << "\n";
	}
}