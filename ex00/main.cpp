/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:02:38 by minsunki          #+#    #+#             */
/*   Updated: 2022/03/29 20:28:39 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat b("minsunki", 1u);
		std::cout << b << std::endl;
		b.decGrade();
		std::cout << b << std::endl;
		b.incGrade();
		b.incGrade();
		std::cout << "do i get printed?" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b("minsunki", 0u);
		std::cout << "uhh" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b("minsunki", 150u);
		std::cout << b << std::endl;
		b.decGrade();
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}