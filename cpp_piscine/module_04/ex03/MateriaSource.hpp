/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:09:39 by utygett           #+#    #+#             */
/*   Updated: 2022/02/02 21:22:05 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include <iostream>
class MateriaSource : public IMateriaSource
{
private:
	AMateria *_slotForMoteria[4];
	bool	_stateOfMateria[4];
public:
	MateriaSource();
	virtual ~MateriaSource();
	MateriaSource( const MateriaSource & for_copy );
	MateriaSource & operator = ( const MateriaSource & for_assign);
	virtual void learnMateria(AMateria* m);
	virtual AMateria* createMateria(std::string const & type);
};

#endif