/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:18:41 by utygett           #+#    #+#             */
/*   Updated: 2022/02/02 20:44:54 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>
Cure :: Cure() : AMateria("cure") {
}

Cure :: ~Cure() {
}

AMateria* Cure :: clone() const {
	return(new Cure(*this));
}

void Cure :: use(ICharacter& target) {
	std :: cout << "* heals " << target.getName() << "\'s wounds *" << std :: endl;
}

Cure :: Cure( const Cure & for_copy ) : AMateria("cure") {
	*this = for_copy;
}

Cure & Cure :: operator = ( const Cure & for_assign) {
	if (this == &for_assign)
		return (*this);
	this->type = for_assign.type;
	return (*this);
}