/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 19:29:25 by afournie          #+#    #+#             */
/*   Updated: 2026/08/25 14:48:23 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 1, 1) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm(target, 145, 137), _target(target) {}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExec())
		throw GradeTooLowException();

	std::string filename = getTarget() + "_shrubbery";
	std::ofstream file(filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("Impossible de creer le fichier " + filename);

	for (int i = 0; i < 5; i++)
		{
			file <<
			"         v" << std::endl <<
			"        >X<" << std::endl <<
			"         A" << std::endl <<
			"        d$b" << std::endl <<
			"      .d\\$$b." << std::endl <<
			"    .d$i$$\\$$b." << std::endl <<
			"       d$$@b" << std::endl <<
			"      d\\$$$ib" << std::endl <<
			"    .d$$$\\$$$b" << std::endl <<
			"  .d$$@$$$$\\$$ib." << std::endl <<
			"      d$$i$$b" << std::endl <<
			"     d\\$$$$@$b" << std::endl <<
			"  .d$@$$\\$$$$$@b." << std::endl <<
			".d$$$$i$$$\\$$$$$$b." << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
		std::endl;
		}

	file.close();
	std::cout << "Shrubbery created at " << filename << std::endl;

}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &ref)
	: AForm(ref)
{
	*this = ref;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &ref)
{
	 if (this != &ref)
	{
		AForm::operator=(ref);
		_target = ref._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
