/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:09:46 by utygett           #+#    #+#             */
/*   Updated: 2022/02/03 14:34:48 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource :: MateriaSource() {
	_stateOfMateria[0] = false;
	_stateOfMateria[1] = false;
	_stateOfMateria[2] = false;
	_stateOfMateria[3] = false;
}

MateriaSource :: ~MateriaSource() {
	for(size_t i = 0; i < 4; i++) {
		if (_stateOfMateria[i] == true)
			delete _slotForMoteria[i];
	}
}

void MateriaSource :: learnMateria(AMateria* m) {
	for (size_t i = 0; i < 4; i++) {
		if (_stateOfMateria[i] == false) {
			_stateOfMateria[i] = true;
			_slotForMoteria[i] = m;
			std :: cout << "Slot [" << i << "] learn [" << m->getType() <<"] materia." << std :: endl;
			return ;
		}
	}
	delete m;
	
}

AMateria* MateriaSource :: createMateria(std::string const & type) {
	for (size_t i = 0; i < 4; i++) {
		if(_stateOfMateria[i] == true && _slotForMoteria[i]->getType().compare(type) == 0) {
			return (_slotForMoteria[i]->clone());
		}
	} 
	std :: cout << type << " is unknow materia." << std :: endl;
	return (NULL);
	
}

MateriaSource :: MateriaSource( const MateriaSource & for_copy ) {
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

MateriaSource & MateriaSource :: operator = ( const MateriaSource & for_assign) {
	if (this == &for_assign)
		return (*this);
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