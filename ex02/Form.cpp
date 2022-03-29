/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:23:17 by minsunki          #+#    #+#             */
/*   Updated: 2022/03/29 01:43:38 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <string>

Form::Form()
	: _name("default"), _signed(false), _reqSign(F_MIN_G), _reqExec(F_MIN_G) 
{}

Form::Form(const Form &f)
	: _name("default"), _signed(false), _reqSign(F_MIN_G), _reqExec(F_MIN_G)
{
	*this = f;
	if (_reqSign < F_MAX_G || _reqExec < F_MAX_G)
		throw GradeTooHighException();
	if (_reqSign > F_MIN_G || _reqExec > F_MIN_G)
		throw GradeTooLowException();
}

Form::Form(const std::string &name)
	: _name(name), _signed(false), _reqSign(F_MIN_G), _reqExec(F_MIN_G) {}

Form::Form(const std::string &name, const unsigned int &reqGrade,
			const unsigned int &reqExec)
	: _name(name), _signed(false), _reqSign(reqGrade), _reqExec(reqExec)
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
	_signed = f.getSigned();
	*(const_cast<unsigned int*>(&_reqSign)) = f.getReqSign();
	*(const_cast<unsigned int*>(&_reqExec)) = f.getReqExec();
	return (*this);
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Form frade too High");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Form grade too low");
}

const char	*Form::CannotCreateFile::what() const throw()
{
	return ("Failed to create file");
}

const char	*Form::FormNotSigned::what() const throw()
{
	return ("Form is not signed");
}

void	Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _reqSign)
		throw Bureaucrat::GradeTooLowException();
	_signed = true;
}

void	Form::execute(Bureaucrat const &executor) const
{
	if (not _signed)
		throw FormNotSigned();
	if (executor.getGrade() > _reqExec)
		throw Bureaucrat::GradeTooLowException();
	this->formAction();
}

void	Form::setName(const std::string &name)
{
	*(const_cast<std::string*>(&_name)) = name;
}

void	Form::setSigned(bool sign)
{
	_signed = sign;
}

void	Form::setGrades(const unsigned int &reqSign, const unsigned int &reqExec)
{
	*(const_cast<unsigned int*>(&_reqSign)) = reqSign;
	*(const_cast<unsigned int*>(&_reqExec)) = reqExec;

	if (_reqSign < F_MAX_G || _reqExec < F_MAX_G)
		throw GradeTooHighException();
	if (_reqSign > F_MIN_G || _reqExec > F_MIN_G)
		throw GradeTooLowException();
}

const std::string	&Form::getName() const
{
	return (_name);
}

const bool	&Form::getSigned() const
{
	return (_signed);
}

const unsigned int	&Form::getReqSign() const
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
	<< f.getReqSign() << ", required grade to exec: " 
	<< f.getReqExec() << ", Signed: " 
	<< (f.getSigned() ? "yes" : "no"));
}