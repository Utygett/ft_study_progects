/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:05:58 by utygett           #+#    #+#             */
/*   Updated: 2022/01/27 14:56:37 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>
#include <iostream>
class WrongAnimal
{
protected:
	std :: string type;
public:
	WrongAnimal( void );
	WrongAnimal( const std :: string & type );
	~WrongAnimal( void );
	WrongAnimal( const WrongAnimal & for_copy );
	WrongAnimal & operator = ( const WrongAnimal & for_assign);
	
	void makeSound( void ) const;
	std :: string getType( void ) const;
};

#endif