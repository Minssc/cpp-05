/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:34:29 by minsunki          #+#    #+#             */
/*   Updated: 2022/04/03 16:48:20 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &i)
{
	*this = i;
}

Intern::~Intern() {}

const Intern	&Intern::operator =(const Intern &i)
{
	// nothing to do.
	static_cast<void>(i);
	return (*this);
}

Form	*Intern::createSCF(const std::string &target) const
{
	Form	*ret = new ShrubberyCreationForm(target);
	std::cout << "Intern creates " << ret->formType() << std::endl;
	return (ret);
}

Form	*Intern::createRRF(const std::string &target) const
{
	Form	*ret = new ShrubberyCreationForm(target);
	std::cout << "Intern creates " << ret->formType() << std::endl;
	return (ret);
}

Form	*Intern::createPPF(const std::string &target) const
{
	Form	*ret = new ShrubberyCreationForm(target);
	std::cout << "Intern creates " << ret->formType() << std::endl;
	return (ret);
}

Form	*Intern::what(const std::string &target) const
{
	static_cast<void>(target);
	std::cout << "the intern doesn't understand your order" << std::endl;
	return (0);
}

static int	matchName(const std::string &name)
{
	std::string	lname;
	int	ret;

	lname = name;
	ret = 0;

	for (long unsigned int i = 0; i < name.size(); ++i) 
		lname[i] = static_cast<char>(std::tolower(name[i]));

	((lname.compare("shrubbery creation") == 0) && (ret = 1));
	((lname.compare("robotomy request") == 0) && (ret = 2));
	((lname.compare("presidential pardon") == 0) && (ret = 3));

	return (ret);
}

Form	*Intern::makeForm(const std::string &name, const std::string &target) const
{
	Form	*(Intern::*f[])(const std::string &target) const = {
		&Intern::what, &Intern::createSCF, &Intern::createRRF, &Intern::createPPF
	};
	int	ft = matchName(name);
	// Form	*ret;

	// ret = 0;
	return (this->*(f[ft]))(target);
	// switch (ft)
	// {
	// 	case 0: default:
	// 		std::cout << "The intern doesn't understand your orders" << std::endl;
	// 		break ;
	// 	case 1: // shruberry
	// 		ret = new ShrubberyCreationForm(target);
	// 		break ;
	// 	case 2: // robotomy
	// 		ret = new RobotomyRequestForm(target);
	// 		break ;
	// 	case 3: // presidential
	// 		ret = new PresidentialPardonForm(target);
	// 		break ;
	// }
	// return (ret);
}