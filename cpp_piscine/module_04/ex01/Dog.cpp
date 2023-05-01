/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:32:38 by utygett           #+#    #+#             */
/*   Updated: 2022/02/03 12:22:31 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog :: Dog( void ) {
	this->type = "Dog";
	std :: cout << "Default Dog constructor called" << std :: endl;
	this->animal_brain = new Brain();
}

Dog :: Dog( const std :: string & type ) {
	std :: cout << "Dog constructor called" << std :: endl;
	this->animal_brain = new Brain();
	this->type = type;
}

Dog :: ~Dog( void ) {
	delete this->animal_brain;
	std :: cout << "Dog destructor called" << std :: endl;

}

Dog :: Dog( const Dog & for_copy ) {
	std :: cout << "Dog copy construcor called" << std :: endl;
	*this = for_copy;
	this->animal_brain = new Brain();
	*this->animal_brain = *for_copy.animal_brain;
}

Dog & Dog :: operator = ( const Dog & for_assign ){
	if (this == &for_assign)
		return (*this);
	std :: cout << "Dog assign operator called" << std :: endl;
	this->type = for_assign.type;
	return (*this);
}

void Dog :: makeSound( void ) const {
	std :: cout << "Dog sound" << std :: endl;
}
