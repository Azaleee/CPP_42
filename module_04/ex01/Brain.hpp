//
// Created by mosmont on 3/10/25.
//

#ifndef CPP_42_BRAIN_HPP
#define CPP_42_BRAIN_HPP

#include <iostream>

#define NB_IDEAS 100

class Brain
{
	public:
		Brain();
		Brain(const Brain &other);
		~Brain();
		Brain &operator=(const Brain &other);

		void 		test(void);
		std::string	getIdea(int i);
		void 		setIdea(int i, std::string str);
	private:
		std::string	ideas[NB_IDEAS];
};


#endif //CPP_42_BRAIN_HPP
