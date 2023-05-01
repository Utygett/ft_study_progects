/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:54:07 by utygett           #+#    #+#             */
/*   Updated: 2022/01/25 16:15:21 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std :: string _name;
public:
	DiamondTrap( void );
	DiamondTrap( std :: string name );
	DiamondTrap( const DiamondTrap & for_copy );
	DiamondTrap & operator = ( const DiamondTrap & for_assign );
	~DiamondTrap( void );
	
	void attack( std::string const & target );
	void whoAmI( void );
	
};

#endif