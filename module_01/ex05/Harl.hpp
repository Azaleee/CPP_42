//
// Created by mosmont on 3/4/25.
//

#ifndef CPP_42_HARL_HPP
#define CPP_42_HARL_HPP

#include <iostream>

class Harl {
public:
	Harl();
	~Harl();
	void	complain(std::string level);
private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
};


#endif //CPP_42_HARL_HPP
