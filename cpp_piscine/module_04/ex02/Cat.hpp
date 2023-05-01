/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:32:44 by utygett           #+#    #+#             */
/*   Updated: 2022/01/29 17:03:55 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *animal_brain;
public:
	Cat( void );
	Cat( const std :: string & type );
	~Cat( void );
	Cat( const Cat & for_copy );
	Cat & operator = ( const Cat & for_assign);

	void makeSound( void ) const;
};



#endif