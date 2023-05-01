/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:31:20 by utygett           #+#    #+#             */
/*   Updated: 2022/02/03 12:21:03 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{

public:
	Dog( void );
	Dog( const std :: string & type );
	~Dog( void );
	Dog( const Dog & for_copy );
	Dog & operator = ( const Dog & for_assign);

	void makeSound( void ) const;
};

#endif