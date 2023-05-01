/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:06:00 by utygett           #+#    #+#             */
/*   Updated: 2022/02/03 12:11:51 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongAnimal.hpp"

WrongAnimal :: WrongAnimal( void ) {
	this->type = "WrongAnimal";
	std :: cout << "Default WrongAnimal constructor called" << std :: endl;
}

WrongAnimal :: WrongAnimal( const std :: string & type) {
	std :: cout << "WrongAnimal constructor called" << std :: endl;
	this->type = type;
}

WrongAnimal :: ~WrongAnimal( void ) {
	std :: cout << "WrongAnimal destructor called" << std :: endl;
}

WrongAnimal :: WrongAnimal( const WrongAnimal & for_copy ) {
	*this = for_copy;
}

WrongAnimal & WrongAnimal :: operator = ( const WrongAnimal & for_assign) {
	if (this == &for_assign)
		return (*this);
	this->type = for_assign.type;
	return (*this);
}

void WrongAnimal :: makeSound( void ) const {
	std :: cout << "WrongAnimal sound" << std :: endl;
}

std :: string WrongAnimal :: getType( void ) const {
	return (this->type);

}