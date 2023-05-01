/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:06:03 by utygett           #+#    #+#             */
/*   Updated: 2022/02/05 14:08:45 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

int main () {
	try {
		Bureaucrat mark("Mark", 200);
	}
	catch (std :: exception & e) {
		std :: cout << e.what() << std :: endl;
	}
	try {
		Bureaucrat bob("Bob", 149);
		std :: cout << bob << std :: endl;
		bob.decrementGrade();
		std :: cout << bob << std :: endl;
	}
	catch (std :: exception & e) {
		std :: cout << e.what() << std :: endl;
	}
	try {
		Bureaucrat clarc("Clarc", 1);
		std :: cout << clarc << std :: endl;
		clarc.incrementGrade();
	}
	catch (std :: exception & e) {
		std :: cout << e.what() << std :: endl;
	}
	Bureaucrat clarc("Clarc", 1);
	std :: cout << clarc << std :: endl;
	try {
		clarc.incrementGrade();
	}
	catch (std :: exception & e) {
		std :: cout << e.what() << std :: endl;

	}
	std :: cout << clarc << std :: endl;
	try {
		clarc.decrementGrade();
	}
	catch (std :: exception & e) {
		std :: cout << e.what() << std :: endl;

	}
	std :: cout << clarc << std :: endl;
	return (0);
}