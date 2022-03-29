/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:51:34 by minsunki          #+#    #+#             */
/*   Updated: 2022/03/29 02:20:19 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERYCREATIONFORM_HPP__
#define __SHRUBBERYCREATIONFORM_HPP__

#include "Form.hpp"
#include <string>

class ShrubberyCreationForm: public Form
{
	private:

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &s);
		ShrubberyCreationForm(const std::string &target);
		virtual	~ShrubberyCreationForm();

		const ShrubberyCreationForm	&operator =(const ShrubberyCreationForm &s);

		virtual void	formAction() const;
		virtual const std::string	formType() const;
};

#endif