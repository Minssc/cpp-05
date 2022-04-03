/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 01:06:17 by minsunki          #+#    #+#             */
/*   Updated: 2022/04/03 16:23:41 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
	: Form("minsunki", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: Form(target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &r)
	: Form(r.getName(), r.getReqSign(), r.getReqExec()) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

const RobotomyRequestForm	&RobotomyRequestForm::operator
								=(const RobotomyRequestForm &r)
{
	// setName(r.getName());
	setSigned(r.getSigned());
	// setGrades(r.getReqSign(), r.getReqExec());
	return (*this);
}

void	RobotomyRequestForm::formAction() const
{
	int r = std::rand() % 100;
	if (r < 50)
		std::cout << getName() << " has been robotomized." << std::endl;
	else
		std::cout << "failed to robotomize " << getName() << std::endl;
}

const std::string	RobotomyRequestForm::formType() const
{
	return ("RobotomyRequestForm");
}