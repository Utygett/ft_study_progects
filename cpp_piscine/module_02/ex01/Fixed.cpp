/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:09:20 by utygett           #+#    #+#             */
/*   Updated: 2022/01/21 15:55:29 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
int Fixed :: getRawBits( void ) const {
	return (this->_raw_value);
}

void Fixed :: setRawBits ( int const raw) {
	this->_raw_value = raw;
}

Fixed & Fixed :: operator = ( Fixed const & for_assign ) {
	std :: cout << "Assignation operator called" << std :: endl;
	this->_raw_value = for_assign.getRawBits();
	return (*this);
}


std :: ostream & operator << (std :: ostream & o, Fixed const & for_stream) {
	o << for_stream.toFloat();
	return (o);
}

Fixed::Fixed() {
	std :: cout << "Default constructor called" << std :: endl;
	this->_raw_value = 0;
}

Fixed::Fixed(const float value_float) {
	std :: cout << "Float constructor called" << std :: endl;
	this->_raw_value = (int)(roundf(value_float * 256));
}

float Fixed :: toFloat( void ) const {
	return ((float)this->_raw_value / 256);
}

int Fixed :: toInt ( void ) const {
	return (this->_raw_value / 256);
}

Fixed::Fixed(const int value_int) {
	std :: cout << "Int constructor called" << std :: endl;
	this->_raw_value = value_int * 256;
}

Fixed::Fixed(const Fixed &for_copy) {
	std :: cout << "Copy constructor called" << std :: endl;
	*this = for_copy;
}

Fixed::~Fixed() {
	std :: cout << "Destructor called" << std :: endl;
}

