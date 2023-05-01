/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:20:15 by utygett           #+#    #+#             */
/*   Updated: 2022/01/16 18:27:27 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main( void ) {
	std :: string str("HI THIS IS BRAIN");
	std :: string *stringPTR = &str;
	std :: string &stringREF = str;
	
	std :: cout << "stringPTR = " << stringPTR << std :: endl;
	std :: cout << "stringREF = " << &stringREF << std :: endl;
	std :: cout << "content stringPTR = " << *stringPTR << std :: endl;
	std :: cout << "content stringREF = " << stringREF << std :: endl;
}