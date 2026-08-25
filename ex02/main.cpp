#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Test 1 : Bureaucrat haut grade, form pas signee ===" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm form("garden");

		std::cout << form << std::endl;
		boss.executeForm(form); // devrait throw FormNotSignedException
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2 : Signature + execution valides ===" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm form("garden");

		boss.signForm(form);
		std::cout << form << std::endl;
		boss.executeForm(form); // devrait creer garden_shrubbery
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3 : Grade insuffisant pour executer ===" << std::endl;
	try
	{
		Bureaucrat lowGrade("Intern", 150);
		Bureaucrat highGrade("Boss", 1);
		ShrubberyCreationForm form("forest");

		highGrade.signForm(form);       // signature avec un grade suffisant
		lowGrade.executeForm(form);     // devrait throw GradeTooLowException
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4 : Grade insuffisant pour signer ===" << std::endl;
	try
	{
		Bureaucrat lowGrade("Intern", 150);
		ShrubberyCreationForm form("park");

		lowGrade.signForm(form); // devrait throw GradeTooHighException (grade trop faible = insuffisant)
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5 : Copie de formulaire ===" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm original("copy_test");
		boss.signForm(original);

		ShrubberyCreationForm copy(original);
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy: " << copy << std::endl;

		boss.executeForm(copy);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
