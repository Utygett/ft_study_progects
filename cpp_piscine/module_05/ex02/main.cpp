/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:06:03 by utygett           #+#    #+#             */
/*   Updated: 2022/02/06 13:09:50 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
int main () {
	PresidentialPardonForm a("Prison");
	ShrubberyCreationForm b("GrandMother");
	RobotomyRequestForm c("Fry");
	Bureaucrat bender("Bender", 1);
	Bureaucrat carl("Carl", 150);
	bender.executeForm(a);
	std :: cout << a << std :: endl;
	try {
		a.execute(bender);
	}
	catch(std::exception & e) {
		std :: cout << e.what() << std :: endl;
	}
	bender.signForm(a);
	carl.signForm(a);
	carl.executeForm(a);
	bender.executeForm(a);
	carl.signForm(c);
	bender.signForm(b);
	bender.signForm(c);
	bender.executeForm(b);
	bender.executeForm(c);
	return (0);
}