/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:32:38 by utygett           #+#    #+#             */
/*   Updated: 2022/02/03 12:11:44 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog :: Dog( void ) {
	this->type = "Dog";
	std :: cout << "Default Dog constructor called" << std :: endl;
}

Dog :: Dog( const std :: string & type ) {
	std :: cout << "Dog constructor called" << std :: endl;
	this->type = type;
}

Dog :: ~Dog( void ) {
	std :: cout << "Dog destructor called" << std :: endl;

}

Dog :: Dog( const Dog & for_copy ) {
	*this = for_copy;
}

Dog & Dog :: operator = ( const Dog & for_assign){
	if (this == &for_assign)
		return (*this);
	this->type = for_assign.type;
	return (*this);
}

void Dog :: makeSound( void ) const {
	std :: cout << "Dog sound" << std :: endl;
}
