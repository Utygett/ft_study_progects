/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:53:11 by utygett           #+#    #+#             */
/*   Updated: 2022/02/07 21:02:08 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>
#include "Convert.hpp"
int main(int argc, char **argv) {
	if (argc != 2) {
		std :: cout << "Error number of arguments" << std :: endl;
		return (1);
	}
	std::cout << std::fixed;
    std::cout << std::setprecision(1);
	try {
		Convert str(argv[1]);
		str.writetoChar();
		str.writetoInt();
		str.writetoFloat();
		str.writetoDouble();

	}
	catch(const std::exception& e) {
		std :: cout << "Conversion is impossible, reason [";
		std :: cout << e.what() << "]" << std :: endl;
	}
	
}