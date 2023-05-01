/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:02:49 by utygett           #+#    #+#             */
/*   Updated: 2022/02/03 14:39:47 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

int main ( void ) {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("curedf");
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	tmp = me->setOnFloor(1);
	me->unequip(1);
	me->use(1, *bob);
	bob->use(0,*me);
	*me = *bob;
	me->use(0, *bob);
	
	delete tmp;
	delete bob;
	delete me;
	delete src;

	Character *mary = new Character("Mary");
	Character *jack = new Character("Jack");
	AMateria *onFloor;
	mary->equip(new Ice);
	mary->equip(new Cure);
	mary->use(0, *jack);
	mary->use(1, *mary);
	onFloor = mary->setOnFloor(1);
	mary->unequip(1);
	mary->use(1, *jack);
	jack->use(0, *mary);
	*jack = *mary;
	jack->use(0, *mary);
	Character anna(*mary);
	anna.use(0, *jack);
	anna.use(1, anna);
	delete mary;
	delete onFloor;
	delete jack;
	return (0);
}