/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:08:19 by minsunki          #+#    #+#             */
/*   Updated: 2022/04/03 16:24:15 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("home", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name)
	: Form(name, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &s)
	: Form(s.getName(), s.getReqSign(), s.getReqExec()) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const ShrubberyCreationForm	&ShrubberyCreationForm::operator 
									=(const ShrubberyCreationForm &s)
{
	// setName(s.getName());
	setSigned(s.getSigned());
	// setGrades(s.getReqSign(), s.getReqExec());
	return (*this);
}

void	ShrubberyCreationForm::formAction() const
{
	std::ofstream	os;
	os.open((getName() + "_shrubbery").c_str());
	if (!os.is_open())
		throw CannotCreateFile();
	os <<
	"     #           \n"
	"    ###          \n"
	"   #####     #   \n"
	"    }|{      |   \n"
	"-----------------\n";
	os.close();
}

const std::string	ShrubberyCreationForm::formType() const
{
	return ("ShrubberyCreationForm");
}