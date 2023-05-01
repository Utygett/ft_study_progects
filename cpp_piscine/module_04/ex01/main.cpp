/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 22:06:09 by utygett           #+#    #+#             */
/*   Updated: 2022/01/29 20:11:23 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main ( void ) {
	Animal *meta[10];
	for (size_t i = 0; i < 10; i++) {
		if (i < 5)
			meta[i] = new Cat();
		else
			meta[i] = new Dog();
	}
	for (size_t i = 0; i < 10; i++) {
		delete meta[i];
	}
	std :: cout << std :: endl;
	Dog basic;
	Cat basic1;
	{
		std :: cout << std :: endl;
		Dog tmp = basic;
		Cat tmp1 = basic1;
		std :: cout << std :: endl;
	}
	std :: cout << std :: endl;
	return (0);
}