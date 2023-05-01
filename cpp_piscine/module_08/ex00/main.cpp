/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:29:15 by utygett           #+#    #+#             */
/*   Updated: 2022/02/12 16:10:53 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>

int main () {

	std::cout << "Test with <vector> " << std::endl;
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	try {
		easyfind(v,6);
		easyfind(v,7);
	}
	catch(const std::exception& e) {
		std::cout << e.what() << '\n';
	}
	std::cout << "Test with <deque> " << std::endl;
	std::deque<int>a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	try {
		easyfind(v,2);
		easyfind(v,7);
	}
	catch(const std::exception& e) {
		std::cout << e.what() << '\n';
	}

}