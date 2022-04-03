/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:01:17 by minsunki          #+#    #+#             */
/*   Updated: 2022/04/03 15:53:53 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("John Doe"), _grade(G_MIN) {}

Bureaucrat::Bureaucrat(const Bureaucrat &b)
	: _name(b.getName()), _grade(b.getGrade()) {}

Bureaucrat::Bureaucrat(const std::string &name, const unsigned int &grade)
	: _name(name), _grade(grade) 
{
	if (_grade < G_MAX)
		throw GradeTooHighException();
	else if (_grade > G_MIN)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

const Bureaucrat	&Bureaucrat::operator =(const Bureaucrat &b)
{
	// *(const_cast<std::string*>(&_name)) = b.getName(); // UB!
	_grade = b.getGrade();
	return (*this);
}

unsigned int	Bureaucrat::getGrade() const
{
	return (_grade);
}

const std::string	&Bureaucrat::getName() const
{
	return (_name);
}

void	Bureaucrat::incGrade()
{
	if (_grade - 1 < G_MAX)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decGrade()
{
	if (_grade + 1 > G_MIN)
		throw GradeTooLowException();
	_grade++;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade too low");
}

std::ostream	&operator <<(std::ostream &o, const Bureaucrat &b)
{
	return (o << b.getName() << ", bureaucrat grade " << b.getGrade());
}