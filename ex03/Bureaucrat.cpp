/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 11:54:34 by afournie          #+#    #+#             */
/*   Updated: 2026/08/25 14:37:12 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

const std::string Bureaucrat::getName() const
{
	return (this->_name);
}

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();

	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();

	_grade++;
}

Bureaucrat::~Bureaucrat() {};

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

void Bureaucrat::signForm(AForm& AForm)
{
	try
	{
		AForm.beSigned(*this);
		std::cout << this->getName() << " signed " << AForm.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << AForm.getName()
			<< " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm& AForm)
{
	try
	{
		AForm.execute(*this);
		std::cout << this->getName() << " execute " << AForm.getName() << " form." << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->getName() << " can't execute " << AForm.getName() << " form because "
			<< e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName()
		<< ", bureaucrat grade "
		<< bureaucrat.getGrade()
		<< ".";

	return out;
}
