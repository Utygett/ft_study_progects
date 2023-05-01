/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:33:49 by utygett           #+#    #+#             */
/*   Updated: 2022/01/18 12:39:30 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

void Karen :: debug( void ){
	std :: cout << "[DEBUG]" << std :: endl;
	std :: cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std :: endl << "I just love it!" << std :: endl;
}

void Karen :: info( void ){
	std :: cout << "[INFO]" << std :: endl;
	std :: cout << "I cannot believe adding extra bacon cost more money." << std :: endl << "You don’t put enough! If you did I would not have to ask for it!" << std :: endl;
}

void Karen :: warning( void ){
	std :: cout << "[WARNING]" << std :: endl;
	std :: cout << "I think I deserve to have some extra bacon for free." << std :: endl << "I’ve been coming here for years and you just started working here last month." << std :: endl;
}

void Karen :: error( void ){
	std :: cout << "[ERROR]" << std :: endl;
	std :: cout << "This is unacceptable, I want to speak to the manager now." << std :: endl;
}

Karen :: Karen(){
	Karen ::f[0] = &Karen :: debug;
	Karen ::f[1] = &Karen :: info;
	Karen ::f[2] = &Karen :: warning;
	Karen ::f[3] = &Karen :: error;
}

Karen :: ~Karen(){
	
}

void Karen :: complain( std::string level ){
	// int level_num;
	
	int i = 0;
	std::string	check_level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (i < 4 && check_level[i] != level) {
		i++;
	}
	enum level_type {DEBUG, INFO, WARNING, ERROR};
	switch(i)
	{
		case DEBUG:
			(this->*(f[0]))();
			std :: cout << std :: endl;
		case INFO:
			(this->*(f[1]))();
			std :: cout << std :: endl;
		case WARNING:
			(this->*(f[2]))();
			std :: cout << std :: endl;
		case ERROR:
			(this->*(f[3]))();
			std :: cout << std :: endl;
			break;
		default :
			std :: cout << "[ Probably complaining about insignificant problems ]" << std :: endl;
	}
}