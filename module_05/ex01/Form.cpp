//
// Created by mosmont on 3/14/25.
//

#include "Form.hpp"

Form::Form() : m_name("Default form"), m_isSigned(false), m_gradeToSign(1), m_gradeToExecute(1) {};

Form::Form(std::string name, const int m_gradeToSign, const int m_gradeToExecute) : m_name(name), m_gradeToSign(m_gradeToSign), m_gradeToExecute(m_gradeToExecute) 
{
	this->m_isSigned = false;
	if (m_gradeToSign > 150 || m_gradeToExecute > 150)
		throw Form::GradeTooLowException();
	else if (m_gradeToSign < 1 || m_gradeToExecute < 1)
		throw Form::GradeTooHighException();
};

Form::Form(const Form &other) : m_name(other.m_name), m_isSigned(false), m_gradeToSign(other.m_gradeToSign), m_gradeToExecute(other.m_gradeToExecute) {};

Form::~Form() {};

std::string Form::getName(void) const
{
	return (m_name);
}

bool Form::getIsSigned(void) const
{
	return (m_isSigned);
}

int Form::getGradeToSign(void) const
{
	return (m_gradeToSign);
}

int Form::getGradeToExecute(void) const
{
	return (m_gradeToExecute);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->m_gradeToSign >= bureaucrat.getGrade())
		this->m_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	std::string signedStatus;
	if (form.getIsSigned())
		signedStatus = "is signed";
	else
		signedStatus = "is not signed";
	out << "Form name : " << form.getName() << "\n"
		<< "Signed status : " << signedStatus << "\n"
		<< "Grade to sign : " << form.getGradeToSign() << "\n"
		<< "Grade to execute : " << form.getGradeToExecute()
		<< std::endl;
	return (out);
}

// Form::Form(const Form &other) : m_name(other.m_name), m_isSigned(other.m_isSigned), m_gradeToSign(other.m_gradeToSign), m_gradeToExecute(other.m_gradeToExecute) {};
