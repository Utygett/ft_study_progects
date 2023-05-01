/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:06:04 by utygett           #+#    #+#             */
/*   Updated: 2022/01/27 15:00:58 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

public:
	WrongCat( void );
	WrongCat( const std :: string & type );
	~WrongCat( void );
	WrongCat( const WrongCat & for_copy );
	WrongCat & operator = ( const WrongCat & for_assign);

	void makeSound( void ) const;
};



#endif