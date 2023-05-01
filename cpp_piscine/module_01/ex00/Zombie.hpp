/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:02:11 by utygett           #+#    #+#             */
/*   Updated: 2022/01/17 22:19:00 by utygett          ###   ########.fr       */
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
	Zombie(std :: string name);
	~Zombie();
	
	void announce( void );

private:
	std :: string zombie_name;
};

#endif

