/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:33:49 by utygett           #+#    #+#             */
/*   Updated: 2022/01/18 12:37:05 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

void Karen :: debug( void ){
	std :: cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std :: endl;
}

void Karen :: info( void ){
	std :: cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std :: endl;
}

void Karen :: warning( void ){
	std :: cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std :: endl;
}

void Karen :: error( void ){
	std :: cout << "This is unacceptable, I want to speak to the manager now." << std :: endl;
}

void Karen :: something_else( void ){
	std :: cout << "You read this becouse you modify my main file" << std :: endl;
}

Karen :: Karen(){
	Karen :: f[0] = &Karen :: debug;
	Karen :: f[1] = &Karen :: info;
	Karen :: f[2] = &Karen :: warning;
	Karen :: f[3] = &Karen :: error;
	Karen :: f[4] = &Karen :: something_else;
}

Karen :: ~Karen(){
	
}

void Karen :: complain( std::string level ){
	int i = 0;
	std :: string check_level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (i < 4 && check_level[i] != level) {
		i++;
	}
	(this->*(f[i]))();
}