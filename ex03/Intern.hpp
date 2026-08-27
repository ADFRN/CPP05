#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


class	Intern
{
	public:
		Intern();
		Intern(Intern const &ref);
		Intern &operator=(Intern const &ref);
		~Intern();

		AForm* makeForm(std::string formName,std::string formTarget);
};

#endif
