/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:09:27 by utygett           #+#    #+#             */
/*   Updated: 2022/01/21 15:55:57 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

// 0000 0000 0000 0000 0000 0000.0000 0000 
class Fixed
{
private:
	int _raw_value;
	const static int _fractional_bits = 8;
	
public:
	Fixed();
	Fixed( Fixed const & for_copy);
	Fixed( int const value_int);
	Fixed( float const value_float);
	~Fixed();
	
	Fixed & operator = ( Fixed const & for_assign );
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};
std :: ostream & operator << (std :: ostream & o, Fixed const & for_stream );


#endif