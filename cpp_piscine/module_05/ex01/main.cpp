/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:06:03 by utygett           #+#    #+#             */
/*   Updated: 2022/02/05 15:30:26 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main () {
	{
		Form a("c43", 21, 21);
		Bureaucrat anna("Anna", 15);

		std :: cout << anna << std :: endl;
		std :: cout << a << std :: endl;
		anna.signForm(a);
		std :: cout << a << std :: endl;
	}
	std :: cout << "<<<<>>>>" << std :: endl;
	{
		Form a("c43", 21, 21);
		Bureaucrat anna("Anna", 22);

		std :: cout << anna << std :: endl;
		std :: cout << a << std :: endl;
		anna.signForm(a);
		std :: cout << a << std :: endl;
	}
	std :: cout << "<<<<>>>>" << std :: endl;
	try
	{
		Form a("c43", -1, 151);
	}
	catch(std :: exception& e)
	{
		std :: cout << e.what() << std :: endl;
	}
	std :: cout << "<<<<>>>>" << std :: endl;
	{
		try
		{
			Form a("c43", 151, 151);
		}
		catch(std :: exception& e)
		{
			std :: cout << e.what() << std :: endl;
		}
		try
		{
			Bureaucrat anna("Anna", -1);
		}
		catch(std :: exception& e)
		{
			std :: cout << e.what() << std :: endl;
		}

		Bureaucrat anna("Anna", 43);
		Form c("c1", 1, 1);
		std :: cout << anna << std :: endl;
		std :: cout << c << std :: endl;
		try {
			c.beSigned(anna);
		}
		catch (std :: exception & e) {
			std :: cout << e.what() << std :: endl;
		}
		anna.signForm(c);
		std :: cout << c << std :: endl;
	}
	return (0);
}