//
// Created by mosmont on 3/14/25.
//

#include "AForm.hpp"

AForm::AForm() : m_name("Default form"), m_isSigned(false), m_gradeToSign(1), m_gradeToExecute(1) {};

AForm::AForm(std::string name, const int m_gradeToSign, const int m_gradeToExecute) : m_name(name), m_gradeToSign(m_gradeToSign), m_gradeToExecute(m_gradeToExecute) 
{
	this->m_isSigned = false;
	if (m_gradeToSign > 150 || m_gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	else if (m_gradeToSign < 1 || m_gradeToExecute < 1)
		throw AForm::GradeTooHighException();
};

AForm::AForm(const AForm &other) : m_name(other.m_name), m_isSigned(false), m_gradeToSign(other.m_gradeToSign), m_gradeToExecute(other.m_gradeToExecute) {};

AForm::~AForm() {};

std::string AForm::getName(void) const
{
	return (m_name);
}

bool AForm::getIsSigned(void) const
{
	return (m_isSigned);
}

int AForm::getGradeToSign(void) const
{
	return (m_gradeToSign);
}

int AForm::getGradeToExecute(void) const
{
	return (m_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->m_gradeToSign >= bureaucrat.getGrade())
		this->m_isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	std::string signedStatus;
	if (form.getIsSigned())
		signedStatus = "is signed";
	else
		signedStatus = "is not signed";
	out << "AForm name : " << form.getName() << "\n"
		<< "Signed status : " << signedStatus << "\n"
		<< "Grade to sign : " << form.getGradeToSign() << "\n"
		<< "Grade to execute : " << form.getGradeToExecute()
		<< std::endl;
	return (out);
}

// AForm::AForm(const AForm &other) : m_name(other.m_name), m_isSigned(other.m_isSigned), m_gradeToSign(other.m_gradeToSign), m_gradeToExecute(other.m_gradeToExecute) {};
