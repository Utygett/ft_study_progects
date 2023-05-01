/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:49:33 by utygett           #+#    #+#             */
/*   Updated: 2022/01/17 12:49:51 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std :: string type) {
	this->type = type;
}

void Weapon :: setType(std :: string weapon_type) {
	this->type = weapon_type;
}

const std :: string& Weapon :: getType( void ) {
	return this->type;
}

Weapon::~Weapon()
{
}
