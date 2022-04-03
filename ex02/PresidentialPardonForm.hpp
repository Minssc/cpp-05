/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 01:28:48 by minsunki          #+#    #+#             */
/*   Updated: 2022/04/03 16:23:23 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRESIDENTIALPARDONFORM_HPP__
#define __PRESIDENTIALPARDONFORM_HPP__

#include "Form.hpp"
#include <string>

class PresidentialPardonForm: public Form
{
	private:

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &p);
		virtual	~PresidentialPardonForm();

		const PresidentialPardonForm	&operator =(const PresidentialPardonForm &p);

		virtual void	formAction() const;
		virtual const std::string	formType() const;
};

#endif