/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:02:38 by minsunki          #+#    #+#             */
/*   Updated: 2022/04/03 16:46:29 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
	Form	*fp;
	Intern	someIntern;

	fp = someIntern.makeForm("shrubbery creation", "home");
	if (fp)
		std::cout << *fp << std::endl;
	delete fp;

	fp = someIntern.makeForm("Robotomy Request", "minsunki");
	if (fp)
		std::cout << *fp << std::endl;
	delete fp;

	fp = someIntern.makeForm("Presidential Pardon", "moulinette");
	if (fp)
		std::cout << *fp << std::endl;
	delete fp;

	fp = someIntern.makeForm("go make a coffee", "minsunki");
	if (fp)
		std::cout << "this should not be happening " << *fp << std::endl;
	delete fp;

	fp = someIntern.makeForm("SHRUBBERY CREATION", "cluster");
	if (fp)
		std::cout << *fp << std::endl;
	delete fp;

	return (0);
}