/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:31:32 by utygett           #+#    #+#             */
/*   Updated: 2022/01/25 16:17:19 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap :: FragTrap( void ) {
	std :: cout << "FragTrap constructor called" << std :: endl;
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
}


FragTrap :: FragTrap( std :: string name) {
	this->_name = name;
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
	std :: cout << "FragTrap constructor called" << std :: endl;
}

FragTrap :: ~FragTrap( void ) {
	std :: cout << "FragTrap destructor called" << std :: endl;
}

FragTrap & FragTrap :: operator = ( const FragTrap & for_assign ){
	this->_AttackDamage = for_assign._AttackDamage;
	this->_EnergyPoints = for_assign._EnergyPoints;
	this->_HitPoints = for_assign._EnergyPoints;
	this->_name = for_assign._name;
	return (*this);
}

FragTrap :: FragTrap( const FragTrap & for_copy ) {
	*this = for_copy;
}

void FragTrap :: highFivesGuys ( void ) {
	std :: cout << "FragTrap " << this->_name << " give me five!!!" << std :: endl;
}