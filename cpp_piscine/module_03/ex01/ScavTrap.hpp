/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:31:24 by utygett           #+#    #+#             */
/*   Updated: 2022/01/23 19:21:05 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap 
{
public:
	ScavTrap( void );
	ScavTrap( std :: string name );
	ScavTrap( const ScavTrap & for_copy );
	ScavTrap & operator = ( const ScavTrap & for_assign );
	~ScavTrap( void );

	void attack( std::string const & target );
	void guardGate( void );
};

#endif