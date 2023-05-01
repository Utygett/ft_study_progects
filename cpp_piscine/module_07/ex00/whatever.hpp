/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 22:26:26 by utygett           #+#    #+#             */
/*   Updated: 2022/02/11 14:47:11 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T& lhs, T& rhs) {
	T buf = lhs;
	lhs = rhs;
	rhs = buf;
}

template <typename T>
T & min (T& lhs, T& rhs) {
	return (lhs < rhs ? lhs : rhs);
}

template <typename T>
T & max(T& lhs, T& rhs) {
	return (lhs > rhs ? lhs : rhs);
}

#endif
