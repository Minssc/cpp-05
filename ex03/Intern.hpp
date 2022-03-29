/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:34:30 by minsunki          #+#    #+#             */
/*   Updated: 2022/03/29 20:51:13 by minsunki         ###   ########seoul.kr  */
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
};


#endif