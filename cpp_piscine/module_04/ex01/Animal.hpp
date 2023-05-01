/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:30:40 by utygett           #+#    #+#             */
/*   Updated: 2022/02/03 13:00:12 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>
class Animal
{
protected:
	std :: string type;
public:
	Animal( void );
	Animal( const std :: string & type );
	virtual ~Animal( void );
	Animal( const Animal & for_copy );
	Animal & operator = ( const Animal & for_assign);
	
	virtual void makeSound( void ) const;
	std :: string getType( void ) const;
};

#endif