/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:01:11 by utygett           #+#    #+#             */
/*   Updated: 2022/01/16 18:15:40 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){
	Zombie *zomb = new Zombie[N];
	for(int i = 0; i < N; i++) {
		zomb[i].set_zombie_name(name);
	}
	return (zomb);
}