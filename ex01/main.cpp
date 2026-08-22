#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	std::cout << "\n----- TEST 1 : Construction basique d'un Bureaucrat et d'un Form -----" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 50);
		Form       form("TaxForm", 40, 20);

		std::cout << bob << std::endl;
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}

	std::cout << "\n----- TEST 2 : Construction Bureaucrat avec grade invalide -----" << std::endl;
	try
	{
		Bureaucrat tooHigh("TooHigh", 0);
		std::cout << tooHigh << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception attrapee : " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat tooLow("TooLow", 151);
		std::cout << tooLow << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception attrapee : " << e.what() << std::endl;
	}

	std::cout << "\n----- TEST 3 : Construction Form avec grade invalide -----" << std::endl;
	try
	{
		Form badForm1("BadForm1", 0, 20);
		std::cout << badForm1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception attrapee : " << e.what() << std::endl;
	}

	try
	{
		Form badForm2("BadForm2", 20, 151);
		std::cout << badForm2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception attrapee : " << e.what() << std::endl;
	}

	std::cout << "\n----- TEST 4 : Signature reussie (grade suffisant) -----" << std::endl;
	{
		Bureaucrat alice("Alice", 10);
		Form       report("ReportForm", 20, 30);

		std::cout << "Avant signature : " << report << std::endl;
		alice.signForm(report);
		std::cout << "Apres signature : " << report << std::endl;
	}

	std::cout << "\n----- TEST 5 : Signature echouee (grade insuffisant) -----" << std::endl;
	{
		Bureaucrat charlie("Charlie", 100);
		Form       secretForm("SecretForm", 10, 10);

		std::cout << "Avant tentative : " << secretForm << std::endl;
		charlie.signForm(secretForm);
		std::cout << "Apres tentative : " << secretForm << std::endl;
	}

	std::cout << "\n----- TEST 6 : Signature avec grade exactement egal (limite) -----" << std::endl;
	{
		Bureaucrat dave("Dave", 25);
		Form       exactForm("ExactForm", 25, 25);

		dave.signForm(exactForm);
		std::cout << exactForm << std::endl;
	}

	std::cout << "\n----- TEST 7 : Tentative de signer un formulaire deja signe -----" << std::endl;
	{
		Bureaucrat eve("Eve", 1);
		Form       alreadySigned("AlreadySigned", 5, 5);

		eve.signForm(alreadySigned);
		std::cout << "Premiere signature : " << alreadySigned << std::endl;

		Bureaucrat frank("Frank", 1);
		frank.signForm(alreadySigned);
		std::cout << "Deuxieme tentative : " << alreadySigned << std::endl;
	}

	std::cout << "\n----- TEST 8 : Copie de Bureaucrat -----" << std::endl;
	{
		Bureaucrat original("Original", 30);
		Bureaucrat copy(original);
		std::cout << original << std::endl;
		std::cout << copy << std::endl;
	}

	return 0;
}
