/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:33:51 by utygett           #+#    #+#             */
/*   Updated: 2022/01/18 12:35:22 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

# include <string>
# include <iostream>
class Karen
{
	
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	void something_else( void );
public:
	Karen();
	~Karen();
	void complain( std::string level );
	void (Karen :: *f[5])( void );
};

#endif