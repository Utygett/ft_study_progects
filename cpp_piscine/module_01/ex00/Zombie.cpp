/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:01:52 by utygett           #+#    #+#             */
/*   Updated: 2022/01/18 12:34:10 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie :: announce( void ) {
	std :: cout << this->zombie_name << " BraiiiiiiinnnzzzZ..." << std :: endl;
	return;
}

Zombie::Zombie( void ) {
	this->zombie_name = "Just a zombie";
	std :: cout << this->zombie_name << " created." << std :: endl;
	return ;
}

Zombie::Zombie(std :: string name) {
	this->zombie_name = name;
	std :: cout << this->zombie_name << " created." << std :: endl;
	this->announce();
	return ;
}

Zombie::~Zombie() {
	std :: cout << this->zombie_name << " was destroy." << std :: endl;
	return ;
}

