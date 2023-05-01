/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:09:20 by utygett           #+#    #+#             */
/*   Updated: 2022/01/18 15:24:34 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed :: getRawBits( void ) const {
	std :: cout << "getRawBits member function called" << std :: endl;
	return (this->_raw_value);
}

void Fixed :: setRawBits ( int const raw) {
	this->_raw_value = raw;
}

void Fixed :: operator=(Fixed &for_assign) {
	std :: cout << "Assignation operator called" << std :: endl;
	_raw_value = for_assign.getRawBits();
}

Fixed::Fixed() {
	std :: cout << "Default constructor called" << std :: endl;
	this->_raw_value = 0;
}

Fixed::Fixed(const Fixed &for_copy) {
	std :: cout << "Copy constructor called" << std :: endl;
	this->_raw_value = for_copy.getRawBits();
}

Fixed::~Fixed() {
	std :: cout << "Destructor called" << std :: endl;
}
