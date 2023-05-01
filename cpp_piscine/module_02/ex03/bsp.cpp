/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:50:32 by utygett           #+#    #+#             */
/*   Updated: 2022/01/22 16:58:14 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed state_point( Point const & a, Point const & b, Point const & point) {
    return (point.getFixedX() - a.getFixedX()) * (b.getFixedY() - a.getFixedY()) - (point.getFixedY() - a.getFixedY()) * (b.getFixedX() - a.getFixedX());
}

bool right_at_line( Point const & a, Point const & b, Point const & c, Point const & point) {
	if(state_point(a,b,c) * state_point(a,b,point) >= Fixed(0))
    	return (true);
	else
		return(false);
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	if (right_at_line(a, b, c, point) && right_at_line(b, c, a, point) && right_at_line(c, a, b, point))
		return (true);
	else
		return (false);
}
