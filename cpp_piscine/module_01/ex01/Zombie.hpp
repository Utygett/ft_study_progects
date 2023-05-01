/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:02:11 by utygett           #+#    #+#             */
/*   Updated: 2022/01/16 16:56:44 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
# include <string>
# include <iostream>
class Zombie
{
	
public:
	Zombie( void );
	~Zombie();
	
	void set_zombie_name (std :: string name);
	void announce( void );

private:
	std :: string zombie_name;
};

#endif

