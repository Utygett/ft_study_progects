/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:31:24 by utygett           #+#    #+#             */
/*   Updated: 2022/01/25 16:04:46 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap 
{
public:
	FragTrap( void );
	FragTrap( std :: string name );
	FragTrap( const FragTrap & for_copy );
	FragTrap & operator = ( const FragTrap & for_assign );
	~FragTrap( void );

	void highFivesGuys( void );
};

#endif