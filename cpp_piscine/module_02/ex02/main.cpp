/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:09:03 by utygett           #+#    #+#             */
/*   Updated: 2022/01/22 18:03:04 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iomanip>
void bit_show(int num) {
	std :: string str;
	for(int i = 1; i <= 32; i++) {
		if (num & (1 << (i - 1)))
			str +=  '1';
		else 
			str += '0';
		if (i % 8 == 0)
			str += ' ';
	}
	for(size_t i = 0; i <= str.size(); i++) {
		std :: cout << str[str.size() - i];
	}
	std :: cout << std :: endl;
}

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
	
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	
	if (Fixed (12) > Fixed (11))
		std :: cout << "12 > 11" << std :: endl;
	if (Fixed (33) < Fixed (55))
		std :: cout << "33 < 55" << std :: endl;
	if (Fixed (33) <= Fixed (33))
		std :: cout << "33 <= 33" << std :: endl;
	if (Fixed (55) >= Fixed (55))
		std :: cout << "55 >= 55" << std :: endl;
	if (Fixed (55) == Fixed (55))
		std :: cout << "55 == 55" << std :: endl;
	if (Fixed (33) != Fixed (55))
		std :: cout << "33 != 55" << std :: endl;
	Fixed a1 = 5.05f;
	Fixed b1 = 2;
	std :: cout << "a1 =" << a1 << std :: endl;
	std :: cout << "b1 =" << b1 << std :: endl;
	std :: cout << a1 + b1 << " = a1 + b1"  << std :: endl;
	std :: cout << a1 - b1 << " = a1 - b1"  << std :: endl;
	std :: cout << a1 * b1 << " = a1 * b1"  << std :: endl;
	std :: cout << a1 / b1 << " = a1 / b1"  << std :: endl;
	return 0;
}