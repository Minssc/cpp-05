/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:01:17 by minsunki          #+#    #+#             */
/*   Updated: 2022/03/29 12:28:26 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(): _name("John Doe"), _grade(G_MIN) {}

Bureaucrat::Bureaucrat(const Bureaucrat &b): _name("John Doe"), _grade(1)
{
	*this = b;
	if (_grade < G_MAX)
		throw GradeTooHighException();
	else if (_grade > G_MIN)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade)
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
	*(const_cast<std::string*>(&_name)) = b.getName();
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

void	Bureaucrat::signForm(Form &f) const
{
	try
	{
		f.beSigned(*this);
		std::cout << _name << " signed " << f.formType()
		<< " target: " << f.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't sign " << f.formType()
		<< " target: " << f.getName()
		<< " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(Form const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << getName() << " executed "
		<< form.formType() << " target: " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << getName() << " failed to execute " << form.formType()
		<< " target: " << form.getName() 
		<< ". reason: " << e.what() << std::endl;
	}
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat Grade Too High");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat Grade Too Low");
}

std::ostream	&operator <<(std::ostream &o, const Bureaucrat &b)
{
	return (o << b.getName() << ", bureaucrat grade " << b.getGrade());
}