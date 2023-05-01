/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:17:18 by utygett           #+#    #+#             */
/*   Updated: 2022/01/25 16:11:25 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void ) {
	DiamondTrap trapA("Trap A");
	DiamondTrap trapB("Trap B");

	trapA.attack(trapB.getName());
	trapB.takeDamage(trapA.getAttackDamage());
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
	trapA.guardGate();
	trapB.guardGate();
	trapA.highFivesGuys();
	trapB.highFivesGuys();
	trapA.whoAmI();
	trapB.whoAmI();
}