/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 01:04:14 by minsunki          #+#    #+#             */
/*   Updated: 2022/04/03 16:23:57 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTOMYREQUESTFORM_HPP__
#define __ROBOTOMYREQUESTFORM_HPP__

#include "Form.hpp"
#include <string>

class RobotomyRequestForm: public Form
{
	private:

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &name);
		RobotomyRequestForm(const RobotomyRequestForm &r);
		~RobotomyRequestForm();

		const RobotomyRequestForm	&operator =(const RobotomyRequestForm &r);

		virtual void	formAction() const;
		virtual const std::string	formType() const;
};

#endif