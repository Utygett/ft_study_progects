/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:29:15 by utygett           #+#    #+#             */
/*   Updated: 2022/02/14 14:41:15 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include "Span.hpp"

int main () {
	std::cout<< "Subject test" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout<< "My test 1" << std::endl;
	Span sp1(3);

	sp1.addNumber(1);
	sp1.addNumber(6);
	sp1.addNumber(7);
	std::cout << sp1.shortestSpan() << std::endl;
	std::cout << sp1.longestSpan() << std::endl;

	std::cout<< "My test 2" << std::endl;
	Span sp2 = Span(300000);
	for (size_t i = 0; i < 300000; i++) {
		sp2.addNumber(i * 2);
	}
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	std::cout<< "My test 3" << std::endl;
	try {
		int a[5] = {-1, 2, 33, 74, 15};
		Span b(4);

		b.fillSpan(a,std::end(a));
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout<< "My test 4" << std::endl;
	try {
		Span a(1);
		a.addNumber(7);
		std::cout << a.shortestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout<< "My test 5" << std::endl;
	try {
		Span a(1);
		a.addNumber(7);
		std::cout << a.longestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout<< "My test 6" << std::endl;
	try {
		Span a(1);
		a.addNumber(7);
		a.addNumber(7);
		a.addNumber(7);
		a.addNumber(7);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout<< "My test 7" << std::endl;

	int a[5] = {-1, 2, 33, 74, 15};
	Span b(5);
	b.fillSpan(a,std::end(a));
	std::cout << b.shortestSpan() << std::endl;
	std::cout << b.longestSpan() << std::endl;

}