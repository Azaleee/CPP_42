//
// Created by mosmont on 3/14/25.
//

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : m_name("Default bureaucrat"), m_grade(1) {}

Bureaucrat::Bureaucrat(std::string const &name, int const &grade) : m_name(name), m_grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw  GradeTooLowException();
	std::cout << "Welcome to the new employee " << this->m_name << " grade is " << \
	this->m_grade << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : m_name(other.m_name), m_grade(other.m_grade) {};

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	if (&other != this)
	{
		this->m_name = other.m_name;
		this->m_grade = other.m_grade;
	}
	return (*this);
}

int Bureaucrat::getGrade() const { return (this->m_grade); }

std::string const &Bureaucrat::getName() const { return (this->m_name); }

void Bureaucrat::incGrade()
{
	if (this->m_grade - 1 < 1)
		throw GradeTooHighException();
	else
		this->m_grade--;
	std::cout << "The new " << \
	this->m_name << " grade is " << \
	this->m_grade << std::endl;
}

void Bureaucrat::decGrade()
{
	if (this->m_grade + 1 > 150)
		throw GradeTooLowException();
	else
		this->m_grade++;
	std::cout << "The new " << \
	this->m_name << " grade is " << \
	this->m_grade << std::endl;
}

std::ostream &operator << (std::ostream &out, const Bureaucrat &target)
{
	out << target.getName() << ", bureaucrat grade " << target.getGrade() << ".";
	return (out);
}
