/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:09:03 by utygett           #+#    #+#             */
/*   Updated: 2022/01/22 18:18:57 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
bool bsp( Point const a, Point const b, Point const c, Point const point);

void point_int_triangle(Point const & a, Point const & b , Point const & c, Point const & point) {
	std :: cout << "Points triangle is: a = (" << a.getFixedX() << ", "  << a.getFixedY() << ')'
				<< " b = (" << b.getFixedX() << ", " << b.getFixedY() << ')'
				<< " c = (" << c.getFixedX() << ", " << c.getFixedY() << ')' << std :: endl;
	std :: cout	<< "point = (" << point.getFixedX() << ", " << point.getFixedY() << ')' ;
	if (bsp(a, b , c , point))
		std :: cout << " in triangle" << std :: endl;
	else
		std :: cout << " not in triangle" << std :: endl;
}

int main( void ) {
	Point a(-1.3f,1.4f);
	Point b(3,1);
	Point c(2.55f,4.32f);
	point_int_triangle(Point (a), Point (b), Point (c), Point (6,2));
	point_int_triangle(Point (a), Point (b), Point (c), Point (2,2));
	point_int_triangle(Point (a), Point (b), Point (c), Point (1.3f,2.1f));
	point_int_triangle(Point (a), Point (b), Point (c), Point (0.1f,2.3f));
	point_int_triangle(Point (a), Point (b), Point (c), Point (-1.1f,3.3f));
	point_int_triangle(Point (a), Point (b), Point (c), Point (-0.5f,1.5f));
}