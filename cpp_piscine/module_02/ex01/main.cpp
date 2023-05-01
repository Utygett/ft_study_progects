/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:09:03 by utygett           #+#    #+#             */
/*   Updated: 2022/01/21 15:26:57 by utygett          ###   ########.fr       */
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
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	

	std::cout << std :: left << std :: setw(25) << "bits 1234.4321f in int is ";
	bit_show((int)1234.4321f);
	std::cout << std :: setw(25) << "bits 1234.4321f in raw is ";
	bit_show(a.getRawBits());
	std::cout << std :: setw(26) << "bits 10 in raw is ";
	bit_show(b.getRawBits());
	std::cout << std :: setw(26) << "bits 42.42f in int is ";
	bit_show((int)42.42f);
	std::cout << std :: setw(26) << "bits 42.42f in raw is ";
	bit_show(c.getRawBits());
	
	std::cout << std :: setw(26) << "bits 10 in int is ";
	bit_show(10);
	std::cout << std :: setw(26) << "bits 10 * 2 int is ";
	bit_show(10 * 2);
	std::cout << std :: setw(26) << "bits 10 * 4 int is ";
	bit_show(10 * 4);
	std::cout << std :: setw(26) << "bits 10 * 8 int is ";
	bit_show(10 * 8);
	std::cout << std :: setw(26) << "bits 10 * 16 int is ";
	bit_show(10 * 16);
	std::cout << std :: setw(26) << "bits 10 * 32 int is ";
	bit_show(10 * 32);
	std::cout << std :: setw(26) << "bits 10 * 64 int is ";
	bit_show(10 * 64);
	std::cout << std :: setw(26) << "bits 10 * 128 int is ";
	bit_show(10 * 128);
	std::cout << std :: setw(26) << "bits 10 * 256 int is ";
	bit_show(10 * 256);
	std::cout << std :: setw(26) << "bits 2560  int is ";
	bit_show(2560);
	std::cout << std :: setw(26) << "bits 2560 / 2 int is ";
	bit_show(2560 / 2);
	std::cout << std :: setw(26) << "bits 2560 / 4 int is ";
	bit_show(2560 / 4);
	std::cout << std :: setw(26) << "bits 2560 / 8 int is ";
	bit_show(2560 / 8);
	std::cout << std :: setw(26) << "bits 2560 / 16 int is ";
	bit_show(2560 / 16);
	std::cout << std :: setw(26) << "bits 2560 / 32 int is ";
	bit_show(2560 / 32);
	std::cout << std :: setw(26) << "bits 2560 / 64 int is ";
	bit_show(2560 / 64);
	std::cout << std :: setw(26) << "bits 2560 / 128 int is ";
	bit_show(2560 / 128);
	std::cout << std :: setw(26) << "bits 2560 / 256 int is ";
	bit_show(2560 / 256);
	

	return 0;
}