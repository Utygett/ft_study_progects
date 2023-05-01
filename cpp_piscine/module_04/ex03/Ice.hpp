/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:08:09 by utygett           #+#    #+#             */
/*   Updated: 2022/02/02 20:42:56 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"
# include "ICharacter.hpp"
class Ice : public AMateria
{
public:
	Ice();
	virtual ~Ice();
	Ice( const Ice & for_copy );
	Ice & operator = ( const Ice & for_assign);
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};




#endif