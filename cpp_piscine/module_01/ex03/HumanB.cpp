/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:15:14 by utygett           #+#    #+#             */
/*   Updated: 2022/01/17 13:25:12 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanB.hpp"


HumanB::HumanB(std :: string name_str) {
	this->name = name_str;
}

void HumanB :: setWeapon ( Weapon &weapon_to_armed ) {
	this->armed_weapon = &weapon_to_armed;
}

void HumanB :: attack ( void ) {
	if(this->armed_weapon)
		std :: cout << this->name  << " attacks with his " << this->armed_weapon->getType() << std :: endl;
	else
		std :: cout << this->name  << " attacks with his " << "arms" << std :: endl;
}

HumanB::~HumanB()
{
}