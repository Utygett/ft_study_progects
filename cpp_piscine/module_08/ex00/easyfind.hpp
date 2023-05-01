/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:40:47 by utygett           #+#    #+#             */
/*   Updated: 2022/02/14 14:29:43 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
int & easyfind(T array , int a) {
	typename T::iterator iter = std::find(array.begin(), array.end(), a);
	if (iter == array.end())
		throw std::invalid_argument("Not found");
	else {
		std :: cout << "Find [" << a << "]" << " at index [" << iter - array.begin()  <<"]" << std :: endl;
		return (*iter);
	}
}

#endif