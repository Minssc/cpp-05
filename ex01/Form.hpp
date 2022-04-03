/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:23:22 by minsunki          #+#    #+#             */
/*   Updated: 2022/04/03 16:01:03 by minsunki         ###   ########seoul.kr  */
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
		bool	_isSigned;
		const unsigned int	_reqSign;
		const unsigned int	_reqExec;

	public:
		Form();
		Form(const Form &f);
		Form(const std::string &name, const unsigned int &reqGrade,
				const unsigned int &reqExec);
		~Form();

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

		void	beSigned(const Bureaucrat &b);

		const std::string	&getName() const;
		const bool	&getSigned() const;
		const unsigned int	&getReqSign() const;
		const unsigned int	&getReqExec() const;
};

std::ostream	&operator <<(std::ostream &o, const Form &f);

#endif