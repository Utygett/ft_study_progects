/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:09:27 by utygett           #+#    #+#             */
/*   Updated: 2022/01/22 18:00:34 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

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
	Fixed & operator ++ ( void );
	Fixed operator ++ ( int );
	Fixed & operator -- ( void );
	Fixed operator -- ( int );
	Fixed operator + ( const Fixed & for_arithmetic_1 ) const;
	Fixed operator - ( const Fixed & for_arithmetic_1 ) const;
	Fixed operator * ( const Fixed & for_arithmetic_1 ) const;
	Fixed operator / ( const Fixed & for_arithmetic_1 ) const;
	bool operator < ( const Fixed & for_comparison_1 ) const;
	bool operator > ( const Fixed & for_comparison_1 ) const;
	bool operator <= ( const Fixed & for_comparison_1 ) const;
	bool operator >= ( const Fixed & for_comparison_1 ) const;
	bool operator != ( const Fixed & for_comparison_1 ) const;
	bool operator == ( const Fixed & for_comparison_1 ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;

	static const Fixed & min( const Fixed & a, const Fixed & b );
	static const Fixed & max( const Fixed & a, const Fixed & b ); 
};
std :: ostream & operator << (std :: ostream & o, const Fixed & for_stream );


#endif