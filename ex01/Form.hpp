/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 15:54:42 by afournie          #+#    #+#             */
/*   Updated: 2026/08/22 19:08:03 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExec;

	public:
		Form(const std::string& name, const int gradeToSign, const int gradeToExec);
		~Form();

		const std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;

		void beSigned(const Bureaucrat& bureaucrat);

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

std::ostream& operator<<(std::ostream& out, const Form& form);


#endif
