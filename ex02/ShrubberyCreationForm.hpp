/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 19:29:22 by afournie          #+#    #+#             */
/*   Updated: 2026/10/12 15:31:04 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <fstream>

class	ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
		ShrubberyCreationForm(void);
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &ref);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &ref);
		~ShrubberyCreationForm();

		std::string getTarget() const;

		void execute(Bureaucrat const & executor) const;
};

#endif
