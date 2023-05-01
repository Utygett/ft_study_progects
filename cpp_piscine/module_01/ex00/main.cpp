/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:01:38 by utygett           #+#    #+#             */
/*   Updated: 2022/01/16 15:53:43 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main( void ) {
	Zombie *zomb = newZombie("Zombie on heap");
	randomChump("Zombie on stack");
	delete zomb;
	return (0);
}

