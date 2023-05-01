/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:32:45 by utygett           #+#    #+#             */
/*   Updated: 2022/02/03 12:22:45 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat :: Cat( void ) {
	this->type = "Cat";
	std :: cout << "Default Cat constructor called" << std :: endl;
	this->animal_brain = new Brain();
}

Cat :: Cat( const std :: string & type ) {
	std :: cout << "Cat constructor called" << std :: endl;
	this->animal_brain = new Brain();
	this->type = type;
}

Cat :: ~Cat( void ) {
	delete this->animal_brain;
	std :: cout << "Cat destructor called" << std :: endl;

}

Cat :: Cat( const Cat & for_copy ) {
	std :: cout << "Cat copy construcor called" << std :: endl;
	*this = for_copy;
	this->animal_brain = new Brain();
	*this->animal_brain = *for_copy.animal_brain;
}

Cat & Cat :: operator = ( const Cat & for_assign ){
	if (this == &for_assign)
		return (*this);
	std :: cout << "Cat assign operator called" << std :: endl;
	this->type = for_assign.type;
	return (*this);
}

void Cat :: makeSound( void ) const {
	std :: cout << "Cat sound" << std :: endl;
}