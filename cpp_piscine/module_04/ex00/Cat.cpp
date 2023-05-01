/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:32:45 by utygett           #+#    #+#             */
/*   Updated: 2022/02/03 12:11:40 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat :: Cat( void ) {
	this->type = "Cat";
	std :: cout << "Default Cat constructor called" << std :: endl;
}

Cat :: Cat( const std :: string & type ) {
	std :: cout << "Cat constructor called" << std :: endl;
	this->type = type;
}

Cat :: ~Cat( void ) {
	std :: cout << "Cat destructor called" << std :: endl;

}

Cat :: Cat( const Cat & for_copy ) {
	*this = for_copy;
}

Cat & Cat :: operator = ( const Cat & for_assign){
	if (this == &for_assign)
		return (*this);
	this->type = for_assign.type;
	return (*this);
}

void Cat :: makeSound( void ) const {
	std :: cout << "Cat sound" << std :: endl;
}
