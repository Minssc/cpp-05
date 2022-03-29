/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:23:17 by minsunki          #+#    #+#             */
/*   Updated: 2022/03/29 20:39:19 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <string>

Form::Form()
	: _name("default"), _isSigned(false), _reqSign(F_MIN_G), _reqExec(F_MIN_G) 
{}

Form::Form(const Form &f)
	: _name("default"), _isSigned(false), _reqSign(F_MIN_G), _reqExec(F_MIN_G)
{
	*this = f;
	if (_reqSign < F_MAX_G || _reqExec < F_MAX_G)
		throw GradeTooHighException();
	if (_reqSign > F_MIN_G || _reqExec > F_MIN_G)
		throw GradeTooLowException();
}

Form::Form(const std::string &name, const unsigned int &reqGrade,
			const unsigned int &reqExec)
	: _name(name), _isSigned(false), _reqSign(reqGrade), _reqExec(reqExec)
{
	if (_reqSign < F_MAX_G || _reqExec < F_MAX_G)
		throw GradeTooHighException();
	if (_reqSign > F_MIN_G || _reqExec > F_MIN_G)
		throw GradeTooLowException();
}

Form::~Form() {}

const Form	&Form::operator =(const Form &f)
{
	*(const_cast<std::string*>(&_name)) = f.getName();
	_isSigned = f.getSigned();
	*(const_cast<unsigned int*>(&_reqSign)) = f.getReqGrade();
	*(const_cast<unsigned int*>(&_reqExec)) = f.getReqExec();
	return (*this);
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Form grade too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Form grade too low");
}

void	Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _reqSign)
		throw GradeTooLowException();
	_isSigned = true;
}

const std::string	&Form::getName() const
{
	return (_name);
}

const bool	&Form::getSigned() const
{
	return (_isSigned);
}

const unsigned int	&Form::getReqGrade() const
{
	return (_reqSign);
}

const unsigned int	&Form::getReqExec() const
{
	return (_reqExec);
}

std::ostream	&operator <<(std::ostream &o, const Form &f)
{
	return (o << "Form Name: " << f.getName() << ", required grade to sign: "
	<< f.getReqGrade() << ", required grade to exec: " 
	<< f.getReqExec() << ", Signed: " 
	<< (f.getSigned() ? "yes" : "no"));
}