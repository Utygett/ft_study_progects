/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 22:06:09 by utygett           #+#    #+#             */
/*   Updated: 2022/02/03 12:21:00 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main ( void ) {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std :: cout << std :: endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete i;
	delete j;
	delete meta;
	std :: cout << std :: endl << "<<<Wrong class>>>"  << std :: endl << std :: endl;
	const WrongAnimal* k = new WrongCat();
	const WrongCat* n = new WrongCat();
	std::cout << k->getType() << " " << std::endl;
	std::cout << n->getType() << " " << std::endl;
	k->makeSound();
	n->makeSound();
	std :: cout << std :: endl;
	delete n;
	delete k;
	return (0);
}
