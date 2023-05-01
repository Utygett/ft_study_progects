/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:08:16 by utygett           #+#    #+#             */
/*   Updated: 2022/02/02 20:43:30 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>
Ice :: Ice() : AMateria("ice") {
}

Ice :: ~Ice() {
}

AMateria* Ice :: clone() const {
	return(new Ice(*this));
}

void Ice :: use(ICharacter& target) {
	std :: cout << "* shoots an ice bolt at " << target.getName() << " *" << std :: endl;
}

Ice :: Ice( const Ice & for_copy ) : AMateria("ice") {
	*this = for_copy;
}

Ice & Ice :: operator = ( const Ice & for_assign) {
	if (this == &for_assign)
		return (*this);
	this->type = for_assign.type;
	return (*this);
}
