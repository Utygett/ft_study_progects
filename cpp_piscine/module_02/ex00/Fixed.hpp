/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:09:27 by utygett           #+#    #+#             */
/*   Updated: 2022/01/20 21:51:58 by utygett          ###   ########.fr       */
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
	Fixed( Fixed const & for_copy );
	~Fixed();
	void operator=( Fixed &for_assign );
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};



#endif