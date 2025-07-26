//
// Created by mosmont on 3/14/25.
//

#ifndef CPP_42_FORM_HPP
#define CPP_42_FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
	private:
		std::string 	m_name;
		bool			m_isSigned;
		const int 		m_gradeToSign;
		const int 		m_gradeToExecute;
	public:
		AForm(void);
		AForm(std::string name, const int m_gradeToSign, const int m_gradeToExecute);
		virtual ~AForm(void);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);

		void			beSigned(const Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const = 0;

		std::string 	getName(void) const;
		bool			getIsSigned(void) const;
		int 			getGradeToSign(void) const;
		int 			getGradeToExecute(void) const;

		class			GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw() 
				{ return ("Grade is to high"); };
		};
		class			GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw() 
				{ return ("Grade is to low"); };
		};
		class			FormNotSigned : public std::exception
		{
			public:
				const char* what() const throw() 
				{ return ("Form is not signed"); };
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &target);

#endif //CPP_42_FORM_HPP
