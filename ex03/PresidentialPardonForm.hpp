/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 19:29:33 by afournie          #+#    #+#             */
/*   Updated: 2026/08/27 12:30:59 by afournie         ###   ########.fr       */
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
		PresidentialPardonForm(); // Private default for the othodox form

	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &ref);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &ref);
		~PresidentialPardonForm();

		std::string getTarget() const;

		void execute(Bureaucrat const & executor) const;

};

#endif
