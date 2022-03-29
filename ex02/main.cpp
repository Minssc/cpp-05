/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:02:38 by minsunki          #+#    #+#             */
/*   Updated: 2022/03/29 12:31:13 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	ShrubberyCreationForm sbf("home");
	RobotomyRequestForm rbf("minsunki");
	PresidentialPardonForm ppf("norminette");

	Bureaucrat me("minsunki", 1u);
	Bureaucrat bob("bob", 150u);
	Bureaucrat tom("tom", 20u);

	me.signForm(sbf);
	me.executeForm(sbf);
	me.executeForm(rbf);
	me.signForm(rbf);
	rbf.execute(me);

	bob.signForm(ppf);
	bob.executeForm(sbf);
	bob.executeForm(rbf);
	bob.executeForm(ppf);
	me.executeForm(ppf);

	tom.signForm(ppf);
	tom.executeForm(ppf);

	me.executeForm(ppf);

	return (0);
}