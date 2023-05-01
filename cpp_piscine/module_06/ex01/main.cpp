/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:53:11 by utygett           #+#    #+#             */
/*   Updated: 2022/02/08 16:50:05 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"
uintptr_t serialize(Data* ptr) {
	return (reinterpret_cast <uintptr_t> (ptr));
}

Data* deserialize(uintptr_t raw) {
	return (reinterpret_cast <Data *> (raw));
}

int main() {
	Data data;
	uintptr_t ptr = serialize(&data);
	Data *pdata = deserialize(ptr);
	if( &data == pdata)
		std :: cout << &data << " = " << pdata << std :: endl;
	else
		std :: cout << &data << " != " << pdata << std :: endl;
	std :: cout << "Addres data : " << &data << std :: endl;
	std :: cout << "Value ptr : " << ptr << std :: endl;
	std :: cout << "Value ptr in hex : " << std :: hex << ptr << std :: dec << std :: endl;
	std :: cout << "Addres pdata : " << pdata << std :: endl;
}