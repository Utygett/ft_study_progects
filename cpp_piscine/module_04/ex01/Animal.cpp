/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:30:27 by utygett           #+#    #+#             */
/*   Updated: 2022/02/03 12:22:13 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal :: Animal( void ) {
	this->type = "Animal";
	std :: cout << "Default Animal constructor called" << std :: endl;
}

Animal :: Animal( const std :: string & type) {
	std :: cout << "Animal constructor called" << std :: endl;
	this->type = type;
}

Animal :: ~Animal( void ) {
	std :: cout << "Animal destructor called" << std :: endl;
}

Animal :: Animal( const Animal & for_copy ) {
	*this = for_copy;
}

Animal & Animal :: operator = ( const Animal & for_assign) {
	if (this == &for_assign)
		return (*this);
	this->type = for_assign.type;
	return (*this);
}

void Animal :: makeSound( void ) const {
	std :: cout << "Animal sound" << std :: endl;
}

std :: string Animal :: getType( void ) const {
	return (this->type);

}