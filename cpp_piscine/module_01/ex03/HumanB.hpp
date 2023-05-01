/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:15:16 by utygett           #+#    #+#             */
/*   Updated: 2022/01/17 13:23:19 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"

class HumanB
{
private:
	std :: string name;
	Weapon *armed_weapon;
public:
	HumanB(std :: string name);
	~HumanB();
	void setWeapon(Weapon &weapon_to_armed);
	void attack( void );
};

#endif