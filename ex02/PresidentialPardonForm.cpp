/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 01:28:44 by minsunki          #+#    #+#             */
/*   Updated: 2022/03/29 02:19:57 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("minsunki")
{
	setGrades(25, 5);
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: Form(target)
{
	setGrades(25, 5);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &p)
	: Form()
{
	*this = p;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

const PresidentialPardonForm	&PresidentialPardonForm::operator
									=(const PresidentialPardonForm &p)
{
	setName(p.getName());
	setSigned(p.getSigned());
	setGrades(p.getReqSign(), p.getReqExec());
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