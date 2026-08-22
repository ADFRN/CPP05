/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 19:29:22 by afournie          #+#    #+#             */
/*   Updated: 2026/08/22 19:29:23 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

class	ShrubberyCreationForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &ref);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &ref);
		~ShrubberyCreationForm();
};

#endif
