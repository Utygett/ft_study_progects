/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:09:20 by utygett           #+#    #+#             */
/*   Updated: 2022/01/22 17:43:33 by utygett          ###   ########.fr       */
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

Fixed & Fixed :: operator = ( const Fixed & for_assign ) {
	this->_raw_value = for_assign.getRawBits();
	return (*this);
}


std :: ostream & operator << ( std :: ostream & o, const Fixed & for_stream ) {
	o << for_stream.toFloat();
	return (o);
}

Fixed :: Fixed() {
	this->_raw_value = 0;
}

Fixed :: Fixed( const float value_float ) {
	this->_raw_value = (int)(roundf(value_float * 256));
}

float Fixed :: toFloat( void ) const {
	return ((float)this->_raw_value / 256);
}

int Fixed :: toInt ( void ) const {
	return (this->_raw_value / 256);
}

Fixed :: Fixed( const int value_int ) {
	this->_raw_value = value_int * 256;
}

Fixed :: Fixed( const Fixed & for_copy ) {
	*this = for_copy;
}

Fixed :: ~Fixed() {
}

bool Fixed :: operator < ( const Fixed  & for_comparison_1 ) const {
	if (this->getRawBits() < for_comparison_1.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed :: operator > ( const Fixed  & for_comparison_1 ) const {
	if (this->getRawBits() > for_comparison_1.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed :: operator <= ( const Fixed & for_comparison_1 ) const {
	if (this->getRawBits() <= for_comparison_1.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed :: operator >= ( const Fixed & for_comparison_1 ) const {
	if (this->getRawBits() >= for_comparison_1.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed :: operator != ( const Fixed & for_comparison_1 ) const {
	if (this->getRawBits() != for_comparison_1.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed :: operator == ( const Fixed & for_comparison_1 ) const {
	if (this->getRawBits() == for_comparison_1.getRawBits())
		return (true);
	else
		return (false);
}

Fixed Fixed :: operator + ( const Fixed & for_arithmetic_1 ) const {
	Fixed buf;
	buf.setRawBits(this->getRawBits() + for_arithmetic_1.getRawBits());
	return (buf);
}

Fixed Fixed :: operator - ( const Fixed & for_arithmetic_1 ) const {
	Fixed buf;
	buf.setRawBits(this->getRawBits() - for_arithmetic_1.getRawBits());
	return (buf);
}

Fixed Fixed :: operator * ( const Fixed & for_arithmetic_1 ) const {
	Fixed buf;
	buf.setRawBits((this->toFloat()  * for_arithmetic_1.getRawBits()));
	return (buf);
}

Fixed Fixed :: operator / ( const Fixed & for_arithmetic_1 ) const {
	Fixed buf;
	buf.setRawBits(this->getRawBits() / for_arithmetic_1.toFloat());
	return (buf);
}

Fixed & Fixed :: operator ++ ( void ) {
	++this->_raw_value;
	return(*this);
}

Fixed Fixed :: operator ++ ( int ) {
	Fixed buf(this->toFloat());
	++this->_raw_value;
	return(buf);
}

Fixed & Fixed :: operator -- ( void ) {
	--this->_raw_value;
	return(*this);
}

Fixed Fixed :: operator -- ( int ) {
	Fixed buf(this->toFloat());
	--this->_raw_value;
	return(buf);
}

const Fixed & Fixed :: min( const Fixed & a, const Fixed & b) {
	if (a > b)
		return (b);
	else
		return (a);
}

const Fixed & Fixed :: max( const Fixed & a, const Fixed & b) {
	if (a < b)
		return (b);
	else
		return (a);
}