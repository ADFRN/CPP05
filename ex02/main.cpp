#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void testShrubbery()
{
	std::cout << "\n===== ShrubberyCreationForm =====" << std::endl;

	Bureaucrat highGrade("Alice", 1);
	Bureaucrat lowGrade("Bob", 150);

	ShrubberyCreationForm form("home");

	std::cout << "\n-- Signature by low grade bureaucrat (should fail) --" << std::endl;
	try
	{
		lowGrade.signForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n-- Signature by high grade bureaucrat (should succeed) --" << std::endl;
	try
	{
		highGrade.signForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n-- Execution by low grade bureaucrat (should fail) --" << std::endl;
	try
	{
		lowGrade.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n-- Execution by high grade bureaucrat (should succeed) --" << std::endl;
	try
	{
		highGrade.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void testRobotomy()
{
	std::cout << "\n===== RobotomyRequestForm =====" << std::endl;

	Bureaucrat exec("Charlie", 1);
	RobotomyRequestForm form("Bender");

	std::cout << "\n-- Execution without signature (should fail) --" << std::endl;
	try
	{
		exec.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n-- Sign then execute several times (50/50 chance) --" << std::endl;
	try
	{
		exec.signForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	for (int i = 0; i < 5; i++)
	{
		try
		{
			exec.executeForm(form);
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
}

void testPresidentialPardon()
{
	std::cout << "\n===== PresidentialPardonForm =====" << std::endl;

	Bureaucrat president("President", 1);
	Bureaucrat intern("Intern", 100);

	PresidentialPardonForm form("Trisolaran");

	std::cout << "\n-- Sign by president --" << std::endl;
	try
	{
		president.signForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n-- Execution attempt by intern (should fail, grade too low) --" << std::endl;
	try
	{
		intern.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n-- Execution by president (should succeed) --" << std::endl;
	try
	{
		president.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	testShrubbery();
	testRobotomy();
	testPresidentialPardon();

	return 0;
}
