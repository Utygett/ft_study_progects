/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:07:05 by utygett           #+#    #+#             */
/*   Updated: 2022/01/18 12:46:44 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"


HumanA::HumanA(std :: string name_str, Weapon &weapon_to_armed) : armed_weapon(weapon_to_armed) {
	this->name = name_str;
}

void HumanA :: attack ( void ) {
	std :: cout << this->name  << " attacks with his " << this->armed_weapon.getType() << std :: endl;
}

HumanA::~HumanA()
{
}