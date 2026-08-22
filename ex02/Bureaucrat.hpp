/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 11:54:38 by afournie          #+#    #+#             */
/*   Updated: 2026/08/22 19:26:08 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat();

		const std::string getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

		void signAForm(AForm& AForm);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
