/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 19:29:27 by afournie          #+#    #+#             */
/*   Updated: 2026/10/12 15:31:20 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <iostream>
#include <cstdlib>
#include <ctime>

class	RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
		RobotomyRequestForm();

	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &ref);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &ref);
		~RobotomyRequestForm();

		std::string getTarget() const;

		void execute(Bureaucrat const & executor) const;

};

#endif
