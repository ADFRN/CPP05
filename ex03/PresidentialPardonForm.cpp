/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 19:29:36 by afournie          #+#    #+#             */
/*   Updated: 2026/08/27 12:42:03 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 1, 1) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm(target, 25, 5), _target(target) {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExec())
		throw GradeTooLowException();

	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &ref)
	: AForm(ref)
{
	*this = ref;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &ref)
{
	if (this != &ref)
	{
		AForm::operator=(ref);
		_target = ref._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}
