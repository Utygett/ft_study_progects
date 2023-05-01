/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 22:41:48 by utygett           #+#    #+#             */
/*   Updated: 2022/01/22 15:33:37 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	Fixed const x;
	Fixed const y;
public:
	Point( void );
	~Point( void );
	Point( const float x, const float y);
	Point( const Fixed x, const Fixed y);
	Point( Point const & for_copy);
	Point & operator = ( Point & for_assign );
	Fixed getFixedX( void ) const;
	Fixed getFixedY( void ) const;
};

#endif
