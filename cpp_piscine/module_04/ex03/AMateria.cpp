/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:07:57 by utygett           #+#    #+#             */
/*   Updated: 2022/02/02 12:04:47 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria :: AMateria(std::string const & type) {
	this->type = type;
}
AMateria :: ~AMateria() {
	
}

std::string const & AMateria :: getType() const {
	return this->type;
}

void AMateria :: use(ICharacter& target) {
	std :: cout << "AMateria try somethin on " << target.getName() << std :: endl;
}