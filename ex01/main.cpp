/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:02:38 by minsunki          #+#    #+#             */
/*   Updated: 2022/03/28 22:56:45 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	Bureaucrat	b_me("minsunki", 100u);
	Bureaucrat	b_admin("admin", 1u);
	Form		f_moul("moulinette", 100u, 100u);
	Form		f_norm("norminette", 150u, 150u);
	Form		f_bonus("bonus", 50u, 50u);

	std::cout << f_moul << std::endl;
	std::cout << f_norm << std::endl;
	std::cout << f_bonus << std::endl;

	b_me.signForm(f_moul);
	b_me.signForm(f_norm);
	b_me.signForm(f_bonus);

	std::cout << f_moul << std::endl;
	std::cout << f_norm << std::endl;
	std::cout << f_bonus << std::endl;



	try
	{
		Form	f("moulinette", 151u, 150u);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form	f("moulinette", 100u, 151u);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form	f("moulinette", 0u, 151u);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form	f("moulinette", 100u, 0u);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	return (0);
}