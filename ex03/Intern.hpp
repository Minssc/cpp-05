/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:34:30 by minsunki          #+#    #+#             */
/*   Updated: 2022/04/03 16:38:07 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include "Form.hpp"
#include <string>

class Intern
{
	private:

	public:
		Intern();
		Intern(const Intern &i);
		~Intern();

		const Intern	&operator =(const Intern &i);
		
		Form	*makeForm(const std::string &name, const std::string &target) const;
		Form	*createSCF(const std::string &target) const;
		Form	*createRRF(const std::string &target) const;
		Form	*createPPF(const std::string &target) const;
		Form	*what(const std::string &target) const;
};


#endif