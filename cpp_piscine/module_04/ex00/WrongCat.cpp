/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:06:02 by utygett           #+#    #+#             */
/*   Updated: 2022/02/03 12:11:59 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat :: WrongCat( void ) {
	this->type = "WrongCat";
	std :: cout << "Default WrongCat constructor called" << std :: endl;
}

WrongCat :: WrongCat( const std :: string & type ) {
	std :: cout << "WrongCat constructor called" << std :: endl;
	this->type = type;
}

WrongCat :: ~WrongCat( void ) {
	std :: cout << "WrongCat destructor called" << std :: endl;

}

WrongCat :: WrongCat( const WrongCat & for_copy ) {
	*this = for_copy;
}

WrongCat & WrongCat :: operator = ( const WrongCat & for_assign){
	if (this == &for_assign)
		return (*this);
	this->type = for_assign.type;
	return (*this);
}

void WrongCat :: makeSound( void ) const {
	std :: cout << "WrongCat sound" << std :: endl;
}
