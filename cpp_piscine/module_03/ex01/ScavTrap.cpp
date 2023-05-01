/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:31:32 by utygett           #+#    #+#             */
/*   Updated: 2022/01/25 16:16:59 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap :: ScavTrap( void ) {
	std :: cout << "Default ScavTrap constructor called" << std :: endl;
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
}


ScavTrap :: ScavTrap( std :: string name) {
	this->_name = name;
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
	std :: cout << "ScavTrap constructor called" << std :: endl;
}

ScavTrap & ScavTrap :: operator = ( const ScavTrap & for_assign ){
	this->_AttackDamage = for_assign._AttackDamage;
	this->_EnergyPoints = for_assign._EnergyPoints;
	this->_HitPoints = for_assign._EnergyPoints;
	this->_name = for_assign._name;
	return (*this);
}

ScavTrap :: ScavTrap( const ScavTrap & for_copy ) {
	*this = for_copy;
}


ScavTrap :: ~ScavTrap( void ) {
	std :: cout << "ScavTrap destructor called" << std :: endl;
}

void ScavTrap :: attack(std::string const & target) {
	if (this->_EnergyPoints > 0 && this->_HitPoints > 0) {
		this->_EnergyPoints--;
		std :: cout << "ScavTrap " << this->_name << " attack " << target
					<< ", causing " << this->_AttackDamage << " points of damage!" << std :: endl;
	} else {
		std :: cout << "ScavTrap " << this->_name << " cant attack. Energy is "
					<< this->_EnergyPoints << " and hitpoint is "
					<< this->_HitPoints << std :: endl;
	}

}

void ScavTrap :: guardGate ( void ) {
	std :: cout << "ScavTrap " << this->_name << " have enterred in Gate keeper mode." << std :: endl;
}