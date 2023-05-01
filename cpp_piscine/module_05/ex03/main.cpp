/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:06:03 by utygett           #+#    #+#             */
/*   Updated: 2022/02/06 13:17:37 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
int main () {
	Intern someRandomIntern;
	Form* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std :: cout << *rrf << std :: endl;
	Bureaucrat fry("Fry", 1);
	fry.signForm(*rrf);
	fry.executeForm(*rrf);
	delete rrf;
	std :: cout << "<<<<<<<>>>>>>>" << std :: endl;
	rrf = someRandomIntern.makeForm("shrubbery creation", "Granny");
	std :: cout << *rrf << std :: endl;
	fry.signForm(*rrf);
	fry.executeForm(*rrf);
	delete rrf;
	std :: cout << "<<<<<<<>>>>>>>" << std :: endl;
	rrf = someRandomIntern.makeForm("presidential pardon", "Joker");
	std :: cout << *rrf << std :: endl;
	fry.signForm(*rrf);
	fry.executeForm(*rrf);
	delete rrf;
	std :: cout << "<<<<<<<>>>>>>>" << std :: endl;
	rrf = someRandomIntern.makeForm("pardon", "Joker");
	
	return (0);
}