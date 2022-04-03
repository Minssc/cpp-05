/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 01:28:44 by minsunki          #+#    #+#             */
/*   Updated: 2022/04/03 16:23:14 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: Form("John Doe", 25u, 5u) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: Form(target, 25u, 5u) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &p)
	: Form(p.getName(), p.getReqSign(), p.getReqExec()) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

const PresidentialPardonForm	&PresidentialPardonForm::operator
									=(const PresidentialPardonForm &p)
{
	// setName(p.getName());
	setSigned(p.getSigned());
	// setGrades(p.getReqSign(), p.getReqExec());
	return (*this);
}

void	PresidentialPardonForm::formAction() const
{
	std::cout << getName() << " has been pardoned by Zaphod Beeblebrox."
	<< std::endl;
}

const std::string	PresidentialPardonForm::formType() const
{
	return ("PresidentialPardonForm");
}