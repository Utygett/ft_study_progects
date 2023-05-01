/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:06:46 by utygett           #+#    #+#             */
/*   Updated: 2022/01/17 13:23:08 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"

class HumanA
{
private:
	std :: string name;
	Weapon &armed_weapon;
public:
	HumanA(std :: string name, Weapon &weapon_to_armed);
	~HumanA();

	void attack( void );
};

#endif