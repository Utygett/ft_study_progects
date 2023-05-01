/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:19:02 by utygett           #+#    #+#             */
/*   Updated: 2022/02/02 20:38:38 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"
# include "ICharacter.hpp"
class Cure : public AMateria
{
public:
	Cure();
	virtual ~Cure();
	Cure( const Cure & for_copy );
	Cure & operator = ( const Cure & for_assign);
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};




#endif