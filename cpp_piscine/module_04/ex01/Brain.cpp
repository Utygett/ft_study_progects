/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:13:09 by utygett           #+#    #+#             */
/*   Updated: 2022/02/03 12:48:17 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain :: Brain( void ) {
	std :: cout << "Default Brain constructor called" << std :: endl;
	for( int i = 0; i < 100; i++){
		ideas[i] = "How to get this world?";
		
	}
	std :: cout << ideas[1] << std :: endl;
}

Brain :: ~Brain( void ) {
	std :: cout << "Brain destructor called" << std :: endl;
}

Brain :: Brain( const Brain & for_copy ) {
	*this = for_copy;
}

Brain & Brain :: operator = ( const Brain & for_assign){
	if (this == &for_assign)
		return (*this);
	std :: cout << "Assign brain called" << std :: endl;
	for(int i = 0; i < 100; i++){
		this->ideas[i] = for_assign.ideas[i];
	}
	return (*this);
}
