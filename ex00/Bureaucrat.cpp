/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:01:17 by minsunki          #+#    #+#             */
/*   Updated: 2022/03/27 23:26:53 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("John Doe"), _grade(1) {}

Bureaucrat::Bureaucrat(const Bureaucrat &b): _name("John Doe"), _grade(1)
{
	*this = b;
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade)
	: _name(name), _grade(grade) 
{
	if (_grade < G_MIN)
		throw GradeTooLowException();
	else if (_grade > G_MAX)
		throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat() {}

const Bureaucrat	&Bureaucrat::operator =(const Bureaucrat &b)
{
	
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
	if (_grade + 1 > G_MAX)
		throw GradeTooHighException();
	_grade++;
}

void	Bureaucrat::decGrade()
{
	if (_grade - 1 < G_MAX)
		throw GradeTooLowException();
	_grade--;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat Grade Too High";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat Grade Too Low";
}

std::ostream	&operator <<(std::ostream &o, const Bureaucrat &b)
{
	return (o << b.getName());
}