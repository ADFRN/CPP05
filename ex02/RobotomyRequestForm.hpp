/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 19:29:27 by afournie          #+#    #+#             */
/*   Updated: 2026/08/22 19:29:28 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

class	RobotomyRequestForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &ref);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &ref);
		~RobotomyRequestForm();
};

#endif
