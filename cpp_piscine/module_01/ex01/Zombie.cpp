/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:01:52 by utygett           #+#    #+#             */
/*   Updated: 2022/01/16 18:17:00 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie :: announce( void ) {
	std :: cout << this->zombie_name << " BraiiiiiiinnnzzzZ..." << std :: endl;
	return;
}
Zombie::Zombie( void ) {
	std :: cout << "Zombie created." << std :: endl;
	return ;
}

Zombie::~Zombie() {
	std :: cout << this->zombie_name << " was destroy." << std :: endl;
	return ;
}

void Zombie :: set_zombie_name( std :: string name) {
	this->zombie_name = name;
	return ;
}

