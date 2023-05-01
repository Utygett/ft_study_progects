/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:17:23 by utygett           #+#    #+#             */
/*   Updated: 2022/01/25 15:04:30 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap :: ClapTrap( void ) {
	std :: cout << "Default ClapTrap constructor called" << std :: endl;
	this->_name = "Default";
	this->_HitPoints = 10;
	this->_EnergyPoints = 10;
	this->_AttackDamage = 0;
}

ClapTrap :: ClapTrap( std :: string name ) {
	std :: cout << "ClapTrap constructor called" << std :: endl;
	this->_name = name;
	this->_HitPoints = 10;
	this->_EnergyPoints = 10;
	this->_AttackDamage = 0;
}

ClapTrap :: ~ClapTrap( void ) {
	std :: cout << "ClapTrap destructor called" << std :: endl;
}

ClapTrap & ClapTrap :: operator = ( const ClapTrap & for_assign ){
	this->_AttackDamage = for_assign._AttackDamage;
	this->_EnergyPoints = for_assign._EnergyPoints;
	this->_HitPoints = for_assign._EnergyPoints;
	this->_name = for_assign._name;
	return (*this);
}

ClapTrap :: ClapTrap( const ClapTrap & for_copy ) {
	*this = for_copy;
}

std :: string  ClapTrap :: getName( void ) const {
	return (this->_name);
}

unsigned int ClapTrap :: getAttackDamage( void ) const {
	return (this->_AttackDamage);
}

void ClapTrap :: setAttackDamage ( unsigned int amount ) {
	this->_AttackDamage = amount;
}

void ClapTrap :: attack(std::string const & target) {
	if (this->_EnergyPoints > 0 && this->_HitPoints > 0) {
		this->_EnergyPoints--;
		std :: cout << "ClapTrap " << this->_name << " attack " << target
					<< ", causing " << this->_AttackDamage << " points of damage!" << std :: endl;
	} else {
		std :: cout << "ClapTrap " << this->_name << " cant attack. Energy is "
					<< this->_EnergyPoints << " and hitpoint is "
					<< this->_HitPoints << std :: endl;
	}

}

void ClapTrap :: takeDamage( unsigned int amount ){
	if (_HitPoints > amount) {
		this->_HitPoints -= amount;
		std :: cout << "ClapTrap " << this->_name << " take " << amount << " damage!"
				<< " And have " << this->_HitPoints << " hitpoints!" << std :: endl;
	} else if (_HitPoints == 0) {
	
	} else {
		this->_HitPoints = 0;
		std :: cout << "ClapTrap " << this->_name << " take " << amount << " damage!"
					<< " And have " << this->_HitPoints << " hitpoints, " 
					<< "and it die." << std :: endl;
	}
}

void ClapTrap :: beRepaired( unsigned int amount ){
	if (this->_EnergyPoints > 0 && this->_HitPoints > 0) {
		this->_EnergyPoints--;
		this->_HitPoints += amount;
		std :: cout << "ClapTrap " << this->_name << " repaired " << amount << " hitpoints!"
		<< " And have " << this->_HitPoints << " hitpoints!" << std :: endl;
	} else {
		std :: cout << "ClapTrap " << this->_name << " cant repaired. Energy is "
					<< this->_EnergyPoints << " and hitpoint is "
					<< this->_HitPoints << std :: endl;
	}
}

void ClapTrap :: showStatus( void ) {
	std :: cout << "Name " << this->_name << " HitPoints " << this->_HitPoints << " Energy " << this->_EnergyPoints << std :: endl;
}