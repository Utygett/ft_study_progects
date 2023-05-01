/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:57:09 by utygett           #+#    #+#             */
/*   Updated: 2022/01/17 20:35:50 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

# include <string>
# include <iostream>

class Weapon
{
private:
	std :: string type;
public:
	Weapon(std :: string weapon_type);
	~Weapon();

	const std :: string& getType( void );
	void setType(std :: string weapon_type);
	
};
#endif