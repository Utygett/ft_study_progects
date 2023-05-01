/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:27:59 by utygett           #+#    #+#             */
/*   Updated: 2022/05/28 17:33:53 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include <iostream>
#include "vector.hpp"
#include <vector>
#include <map>
#include "map.hpp"
#include <utility> 
#include <time.h>
#include <sys/time.h>


int main()
    {
	time_t g_start1 = timer();
    std::cout << ft::is_integral<float>::value << '\n';
    std::cout << ft::is_integral<int>::value << '\n';
    std::cout << ft::is_integral<bool>::value << '\n';
	
	time_t g_start2 = timer();

	std::cout << "DIFF "<<g_start2 - g_start1 << std::endl;
}
