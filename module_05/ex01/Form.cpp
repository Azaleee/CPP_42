//
// Created by mosmont on 3/14/25.
//

#include "Form.hpp"

Form::Form() : 	m_name("Default form"), m_isSigned(false), m_gradeToSign(1) \
				m_gradeToExecute(1) {};

Form::Form(const Form &other) : m_name(other.m_name), m_isSigned(other.m_isSigned), \
								m_gradeToSign(other.m_gradeToSign), \
								m_gradeToExecute(other.m_gradeToExecute){}

Form::