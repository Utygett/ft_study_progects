/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:32:12 by utygett           #+#    #+#             */
/*   Updated: 2022/02/03 13:56:12 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include <iostream>

class Character : public ICharacter
{
private:
	std :: string _name;
	AMateria *_slotForMoteria[4];
	bool	_stateOfMateria[4];
public:
	Character();
	Character(std :: string name);
	virtual ~Character();
	Character( const Character & for_copy );
	Character & operator = ( const Character & for_assign);
	virtual std :: string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
	virtual AMateria* setOnFloor(int idx);
};

#endif