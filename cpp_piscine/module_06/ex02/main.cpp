/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:53:11 by utygett           #+#    #+#             */
/*   Updated: 2022/02/08 19:46:39 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

# include <string>
# include <iostream>

Base * generate(void) {
	srand (time(NULL));
	int i = std :: rand() % 3;
	enum {typeA, typeB, typeC};
	switch (i)
	{
	case typeA :
		return (new A());
	case typeB :
		return (new B());
	case typeC :
		return (new C());
	default:
		break;
	}
	return (NULL);
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL)
		std :: cout << "A" << std :: endl;
	else if (dynamic_cast<B*>(p)!= NULL)
		std :: cout << "B" << std :: endl;
	else if (dynamic_cast<C*>(p)!= NULL)
		std :: cout << "C" << std :: endl;
	else
		std :: cout << "Other type" << std :: endl;
}

void identify(Base& p) {
	try {
		A &a = dynamic_cast<A&>(p);
		std :: cout << "A" << std :: endl;
		(void) a;
	}
	catch(std :: bad_cast & e) {
		try {
		B &b = dynamic_cast<B&>(p);
		std :: cout << "B" << std :: endl;
		(void) b;
		}
		catch(std :: bad_cast & e) {
			try {
			C &c = dynamic_cast<C&>(p);
			std :: cout << "C" << std :: endl;
			(void) c;
			}
			catch(std :: bad_cast & e) {
				std :: cout << e.what() << std :: endl;
			}
		}
	}
	
}

int main() {
	Base *buf = generate();

	identify(buf);
	identify(*buf);
	Base a;
	identify(&a);
	identify(a);
	delete buf;
}