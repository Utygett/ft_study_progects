/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:08:57 by utygett           #+#    #+#             */
/*   Updated: 2022/02/09 22:38:37 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void iter(T * mas, size_t size, void(f)(T & elem)) {
	for(size_t i = 0; i < size; i++) {
		f(mas[i]);
	}
}

template <typename T>
void iter(T * mas, size_t size, void(f)(const T & elem)) {
	for(size_t i = 0; i < size; i++) {
		f(mas[i]);
	}
}

template <typename T> 
void print( T const & x ) {
	std::cout << x << std::endl;
	return;
}

#endif