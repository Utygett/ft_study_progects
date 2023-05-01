/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:01:38 by utygett           #+#    #+#             */
/*   Updated: 2022/01/16 18:18:27 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main( void ) {
	int nb_zombie = 5;
	Zombie *zombs = zombieHorde(nb_zombie, "Dude");
	
	for(int i = 0;i < nb_zombie; i++) {
		zombs[i].announce();
	}
	delete[] zombs;
	return (0);
}

