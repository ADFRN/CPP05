/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 15:54:51 by afournie          #+#    #+#             */
/*   Updated: 2026/08/22 19:20:01 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, const int gradeToSign, const int gradeToExec)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
}

Form::~Form() {}

const std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getIsSigned() const
{
	return (this->_isSigned);
}

int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExec() const
{
	return (this->_gradeToExec);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	out << form.getName()
		<< ", form signed : "
		<< form.getIsSigned()
		<< ", grade to sign :"
		<< form.getGradeToSign()
		<< ", grade to exec : "
		<< form.getGradeToExec()
		<< ".";

	return out;
}
