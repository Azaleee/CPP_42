//
// Created by mosmont on 3/14/25.
//

#ifndef CPP_42_BUREAUCRAT_HPP
#define CPP_42_BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);

		std::string getName(void) const;
		int 		getGrade(void) const;
		void		incGrade(void);
		void		decGrade(void);

		class		GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw() { return ("Grade is to high"); };
		};
		class		GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw() { return ("Grade is to low"); };
		};
	private:
		std::string m_name;
		int 		m_grade;
};

std::ostream &operator << (std::ostream &out, const Bureaucrat &target);

#endif //CPP_42_BUREAUCRAT_HPP
