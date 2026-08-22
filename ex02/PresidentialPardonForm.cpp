/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 19:29:36 by afournie          #+#    #+#             */
/*   Updated: 2026/08/22 19:29:37 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &ref)
{
	*this = ref;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &ref)
{
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}
