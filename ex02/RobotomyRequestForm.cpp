/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 19:29:30 by afournie          #+#    #+#             */
/*   Updated: 2026/08/22 19:29:31 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &ref)
{
	*this = ref;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &ref)
{
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}
