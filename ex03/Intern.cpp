#include "Intern.hpp"

Intern::Intern() {}

static AForm* createShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string formTarget)
{
	const std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*formCreators[3])(const std::string&) = {
		&createShrubbery,
		&createRobotomy,
		&createPresidential
	};

	for (int i = 0; i < 3; i++) {
		if (formNames[i] == formName) {
			AForm* form = formCreators[i](formTarget);
			std::cout << "Intern creates " << formName << std::endl;
			return form;
		}
	}

	std::cerr << "Error: form \"" << formName << "\" does not exist." << std::endl;
	return NULL;
}

Intern::Intern(Intern const &ref)
{
	*this = ref;
}

Intern	&Intern::operator=(Intern const &ref)
{
	if (this != &ref)
		*this = ref;
	return (*this);
}

Intern::~Intern() {}
