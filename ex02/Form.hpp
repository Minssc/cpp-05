/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:23:22 by minsunki          #+#    #+#             */
/*   Updated: 2022/03/29 20:49:24 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP__
#define __FORM_HPP__

#define F_MAX_G 1u
#define F_MIN_G 150u

#include <string>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string _name;
		bool	_signed;
		const unsigned int	_reqSign;
		const unsigned int	_reqExec;

	public:
		Form();
		Form(const Form &f);
		Form(const std::string &name);
		Form(const std::string &name, const unsigned int &reqGrade,
				const unsigned int &reqExec);
		virtual	~Form();

		const Form	&operator =(const Form &f);

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

		class CannotCreateFile: public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class FormNotSigned: public std::exception
		{
			public:
				const char	*what() const throw();
		};

		void	beSigned(const Bureaucrat &b);
		void	execute(Bureaucrat const & executor) const;
		virtual void	formAction() const = 0;
		virtual const std::string	formType() const = 0;
		
		void	setName(const std::string &name);
		void	setSigned(bool sign);
		void	setGrades(const unsigned int &reqSign, const unsigned int &reqExec);

		const std::string	&getName() const;
		const bool	&getSigned() const;
		const unsigned int	&getReqSign() const;
		const unsigned int	&getReqExec() const;
};

std::ostream	&operator <<(std::ostream &o, const Form &f);

#endif