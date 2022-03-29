/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:59:35 by minsunki          #+#    #+#             */
/*   Updated: 2022/03/29 20:37:16 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#define G_MIN 150u
#define G_MAX 1u

#include <string>
#include <iostream>

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int		_grade;

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &b);
		Bureaucrat(const std::string &name, const unsigned int &grade);
		~Bureaucrat();

		const Bureaucrat	&operator =(const Bureaucrat &b);
		
		unsigned int		getGrade() const;
		const std::string	&getName() const;

		void	incGrade();
		void	decGrade();
		void	signForm(Form &f) const;
	
		class GradeTooHighException: public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

std::ostream	&operator <<(std::ostream &o, const Bureaucrat &b);

#endif