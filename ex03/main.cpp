#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>

int main() {
	Intern intern;
	AForm* form;

	std::cout << "----- Test 1: creation de forms valides -----" << std::endl;

	form = intern.makeForm("shrubbery creation", "home");
	delete form;

	form = intern.makeForm("robotomy request", "Bender");
	delete form;

	form = intern.makeForm("presidential pardon", "Zaphod");
	delete form;

	std::cout << "\n----- Test 2: form inexistant -----" << std::endl;

	form = intern.makeForm("nuclear launch codes", "someone");
	if (form == NULL)
		std::cout << "form est bien NULL, comme attendu." << std::endl;

	std::cout << "\n----- Test 3: cycle complet (creation + signature + execution) -----" << std::endl;

	Bureaucrat boss("Boss", 1); // grade assez haut pour tout signer/executer
	AForm* rrf = intern.makeForm("robotomy request", "Bender");

	if (rrf) {
		try {
			boss.signForm(*rrf);
			boss.executeForm(*rrf);
		} catch (const std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		delete rrf;
	}

	std::cout << "\n----- Test 4: intern qui cree plusieurs forms d'affilee -----" << std::endl;

	std::string formsToTest[4] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon",
		"invalid form"
	};

	std::string targets[4] = {
		"target0",
		"target1",
		"target2",
		"target3"
	};

	for (int i = 0; i < 4; i++) {
		AForm* f = intern.makeForm(formsToTest[i], targets[i]);
		if (f) {
			std::cout << *f << std::endl;
			delete f;
		}
	}

	return 0;
}
