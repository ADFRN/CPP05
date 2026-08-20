/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 11:54:40 by afournie          #+#    #+#             */
/*   Updated: 2026/08/20 15:49:09 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    // =========================
    // Test 1 : constructeur + getters
    // =========================
    std::cout << "===== Test 1 =====" << std::endl;

    Bureaucrat bob("Bob", 42);

    std::cout << "Name: " << bob.getName() << std::endl;
    std::cout << "Grade: " << bob.getGrade() << std::endl;
    std::cout << bob << std::endl;


    // =========================
    // Test 2 : incrementGrade
    // =========================
    std::cout << "\n===== Test 2 =====" << std::endl;

    Bureaucrat alice("Alice", 3);

    std::cout << alice << std::endl;

    alice.incrementGrade();
    std::cout << alice << std::endl;

    alice.incrementGrade();
    std::cout << alice << std::endl;


    // =========================
    // Test 3 : incrementGrade trop haut
    // =========================
    std::cout << "\n===== Test 3 =====" << std::endl;

    try
    {
        alice.incrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << alice << std::endl;


    // =========================
    // Test 4 : decrementGrade
    // =========================
    std::cout << "\n===== Test 4 =====" << std::endl;

    Bureaucrat charlie("Charlie", 148);

    std::cout << charlie << std::endl;

    charlie.decrementGrade();
    std::cout << charlie << std::endl;

    charlie.decrementGrade();
    std::cout << charlie << std::endl;


    // =========================
    // Test 5 : decrementGrade trop bas
    // =========================
    std::cout << "\n===== Test 5 =====" << std::endl;

    try
    {
        charlie.decrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << charlie << std::endl;


    // =========================
    // Test 6 : constructeur grade trop haut
    // =========================
    std::cout << "\n===== Test 6 =====" << std::endl;

    try
    {
        Bureaucrat high("High", 0);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }


    // =========================
    // Test 7 : constructeur grade trop bas
    // =========================
    std::cout << "\n===== Test 7 =====" << std::endl;

    try
    {
        Bureaucrat low("Low", 151);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }


    // =========================
    // Test 8 : limites valides
    // =========================
    std::cout << "\n===== Test 8 =====" << std::endl;

    Bureaucrat highest("Highest", 1);
    Bureaucrat lowest("Lowest", 150);

    std::cout << highest << std::endl;
    std::cout << lowest << std::endl;

    return 0;
}
