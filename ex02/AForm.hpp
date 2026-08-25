/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 15:54:42 by afournie          #+#    #+#             */
/*   Updated: 2026/08/22 19:08:03 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExec;

	public:
		AForm();
		AForm(const std::string& name, const int gradeToSign, const int gradeToExec);
		virtual ~AForm();

		const std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;

		virtual void execute(Bureaucrat const & executor) const = 0;

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

		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		AForm &operator=(AForm const &ref);
		AForm(AForm const &ref);
};

std::ostream& operator<<(std::ostream& out, const AForm& AForm);


#endif
