/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:17:18 by utygett           #+#    #+#             */
/*   Updated: 2022/01/25 15:02:30 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap trapA("Trap A");
	ClapTrap trapB("Trap B");

	trapA.attack(trapB.getName());
	trapB.takeDamage(trapA.getAttackDamage());
	trapA.setAttackDamage(4);
	trapA.attack(trapB.getName());
	trapB.takeDamage(trapA.getAttackDamage());
	trapA.attack(trapB.getName());
	trapB.takeDamage(trapA.getAttackDamage());
	trapA.attack(trapB.getName());
	trapB.takeDamage(trapA.getAttackDamage());
	trapA.attack(trapB.getName());
	trapB.takeDamage(trapA.getAttackDamage());
	trapB.attack(trapA.getName());
	trapB.beRepaired(5);
	trapA.beRepaired(5);
	trapA.showStatus();
	trapB.showStatus();
}