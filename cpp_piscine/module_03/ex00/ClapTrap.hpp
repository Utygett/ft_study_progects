/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:17:21 by utygett           #+#    #+#             */
/*   Updated: 2022/01/24 19:08:03 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <string>
#include <iostream>

class ClapTrap
{
private:
	std :: string _name;
	unsigned int _HitPoints;
	unsigned int _EnergyPoints;
	unsigned int _AttackDamage;
public:
	ClapTrap( void );
	ClapTrap( std :: string name );
	ClapTrap( const ClapTrap & for_copy );
	ClapTrap & operator = ( const ClapTrap & for_assign );
	~ClapTrap( void );
	
	std :: string getName( void ) const;
	unsigned int getAttackDamage( void ) const;
	void setAttackDamage ( unsigned int amount );
	void attack( std::string const & target );
	void takeDamage( unsigned int amount );
	void beRepaired( unsigned int amount );
	void showStatus( void );
};

#endif