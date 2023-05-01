/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 22:41:52 by utygett           #+#    #+#             */
/*   Updated: 2022/01/22 15:34:17 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point :: Point( void ) : x(0), y(0) {
}

Point :: Point( const float x, const float y) : x(x), y(y) {
}

Point :: Point( const Fixed x, const Fixed y) : x(x), y(y) {
}

Point :: ~Point( void ) {
}

Point & Point :: operator = ( Point & for_assign ){
	return (for_assign);
}

Point :: Point( const Point &for_copy ) : x(for_copy.getFixedX()), y(for_copy.getFixedY()) {
}

Fixed Point :: getFixedX ( void ) const {
	return (this->x);
}
Fixed Point :: getFixedY ( void ) const {
	return (this->y);
}