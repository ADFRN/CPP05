/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 19:29:30 by afournie          #+#    #+#             */
/*   Updated: 2026/08/27 12:45:06 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 1, 1) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm(target, 72, 45), _target(target) {}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExec())
		throw GradeTooLowException();

	std::cout << "* drilling noises *" << std::endl;

	if (std::rand() % 100 < 50)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "The robotomy of " << _target << " failed" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &ref)
	: AForm(ref)
{
	*this = ref;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &ref)
{
	if (this != &ref)
	{
		AForm::operator=(ref);
		_target = ref._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}
