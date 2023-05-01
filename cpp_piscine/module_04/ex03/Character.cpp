/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:32:13 by utygett           #+#    #+#             */
/*   Updated: 2022/02/02 21:09:30 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character :: Character() {
	_stateOfMateria[0] = false;
	_stateOfMateria[1] = false;
	_stateOfMateria[2] = false;
	_stateOfMateria[3] = false;
}
Character :: Character(std :: string name) {
	_name = name;
	_stateOfMateria[0] = false;
	_stateOfMateria[1] = false;
	_stateOfMateria[2] = false;
	_stateOfMateria[3] = false;
}

Character :: ~Character() {
	for(size_t i = 0; i < 4; i++) {
		if (_stateOfMateria[i] == true)
			delete _slotForMoteria[i];
	}
}

std :: string const & Character ::  getName() const {
	return (_name);
}
void Character :: equip(AMateria* m) {
	for (size_t i = 0; i < 4; i++) {
		if (_stateOfMateria[i] == false) {
			_stateOfMateria[i] = true;
			_slotForMoteria[i] = m;
			std :: cout << "Character " << _name << " equip in [" << i << "] slot [" << m->getType() <<"] materia." << std :: endl;
			break ;
		}
	}
	

}
void Character :: unequip(int idx) {
	_stateOfMateria[idx] = false;
	_slotForMoteria[idx] = NULL;

}
void Character :: use(int idx, ICharacter& target){
	if(_stateOfMateria[idx] == true)
		_slotForMoteria[idx]->use(target);
	else if (idx < 4)
		std :: cout << "Slot [" << idx << "] of " << _name <<" is empty." << std :: endl;
	else
		std :: cout << "Slot [" << idx << "] of " << _name <<" is unexisting." << std :: endl;
	
}

AMateria* Character :: setOnFloor(int idx) {
	if(_stateOfMateria[idx] == true)
		return (_slotForMoteria[idx]);
	else
		return (NULL);
}

Character :: Character( const Character & for_copy ) {
	_name = for_copy._name;
	for(size_t i = 0; i < 4; i++) {
		if (_stateOfMateria[i] == true)
			delete _slotForMoteria[i];
		_stateOfMateria[i] = false;
	}
	for (size_t i = 0; i < 4; i++)
	{
		if(for_copy._stateOfMateria[i] == true)
			_slotForMoteria[i] = for_copy._slotForMoteria[i]->clone();
		_stateOfMateria[i] = for_copy._stateOfMateria[i];
	}
}

Character & Character :: operator = ( const Character & for_assign) {
	if (this == &for_assign)
		return (*this);
	_name = for_assign._name;
	for(size_t i = 0; i < 4; i++) {
		if (_stateOfMateria[i] == true)
			delete _slotForMoteria[i];
		_stateOfMateria[i] = false;
	}
	for (size_t i = 0; i < 4; i++)
	{
		if(for_assign._stateOfMateria[i] == true)
			_slotForMoteria[i] = for_assign._slotForMoteria[i]->clone();
		_stateOfMateria[i] = for_assign._stateOfMateria[i];
	}
	return (*this);
}
