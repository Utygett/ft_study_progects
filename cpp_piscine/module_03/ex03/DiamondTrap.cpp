/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:54:14 by utygett           #+#    #+#             */
/*   Updated: 2022/01/25 16:18:03 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap :: DiamondTrap( void ) {
	std :: cout << "DiamondTrap constructor called" << std :: endl;
}


DiamondTrap :: DiamondTrap( std :: string name) {
	ClapTrap :: _name = name;
	ClapTrap :: _name += "_clap_name";
	this->_HitPoints = FragTrap :: _HitPoints;
	this->_EnergyPoints = ScavTrap :: _EnergyPoints;
	this->_AttackDamage = FragTrap :: _AttackDamage;
	this->_name = name;
	std :: cout << "DiamondTrap constructor called" << std :: endl;
}

DiamondTrap :: ~DiamondTrap( void ) {
	std :: cout << "DiamondTrap destructor called" << std :: endl;
}

DiamondTrap & DiamondTrap :: operator = ( const DiamondTrap & for_assign ){
	this->_AttackDamage = for_assign._AttackDamage;
	this->_EnergyPoints = for_assign._EnergyPoints;
	this->_HitPoints = for_assign._EnergyPoints;
	this->_name = for_assign._name;
	return (*this);
}

DiamondTrap :: DiamondTrap( const DiamondTrap & for_copy ) {
	*this = for_copy;
}

void DiamondTrap :: attack(std::string const & target) {
	ScavTrap :: attack(target);
}

void DiamondTrap :: whoAmI( void ) {
	std :: cout << "DiamondTrap name [" << this->_name << "]" << std :: endl;
	std :: cout << "ClapTrap name [" << ClapTrap :: _name << "]" << std :: endl;
}