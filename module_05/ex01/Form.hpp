//
// Created by mosmont on 3/14/25.
//

#ifndef CPP_42_FORM_HPP
#define CPP_42_FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	private:
		std::string m_name;
		bool		m_isSigned;
		const int 	m_gradeToSign;
		const int 	m_gradeToExecute;
	public:
		Form(void);
		Form(std::string name, const int m_gradeToSign, const int m_gradeToExecute);
		~Form(void);
		Form(const Form &other);
		Form &operator=(const Form &other);

		void		beSigned(const Bureaucrat &bureaucrat);

		std::string getName(void) const;
		bool		getIsSigned(void) const;
		int 		getGradeToSign(void) const;
		int 		getGradeToExecute(void) const;

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
};

std::ostream &operator<<(std::ostream &out, const Form &target);

#endif //CPP_42_FORM_HPP
