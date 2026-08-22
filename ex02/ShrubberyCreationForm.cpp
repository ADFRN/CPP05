/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 19:29:25 by afournie          #+#    #+#             */
/*   Updated: 2026/08/22 19:29:26 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &ref)
{
	*this = ref;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &ref)
{
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}
