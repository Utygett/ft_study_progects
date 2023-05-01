/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:07:12 by utygett           #+#    #+#             */
/*   Updated: 2022/02/11 14:41:45 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Iter.hpp"


void square(int & i) {
	 i *= i; };

void toUp(char & a) {
	a = toupper(a);
}

int main() {
	int a[3] = {1, 4, 6};
	:: iter(a, 3, square);
	:: iter(a, 3, print);

	char str[6] = {'h', 'e', 'l', 'l', 'o', 'w'};
	std :: cout << str << std :: endl;
	:: iter(str, 6, toUp);
	:: iter(str, 6, print);


}