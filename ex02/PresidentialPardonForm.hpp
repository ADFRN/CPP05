/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 19:29:33 by afournie          #+#    #+#             */
/*   Updated: 2026/10/12 15:31:32 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <fstream>

class	PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
		PresidentialPardonForm();

	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &ref);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &ref);
		~PresidentialPardonForm();

		std::string getTarget() const;

		void execute(Bureaucrat const & executor) const;

};

#endif
