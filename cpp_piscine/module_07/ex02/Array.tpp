/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:04:27 by utygett           #+#    #+#             */
/*   Updated: 2022/02/11 15:23:08 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"
template <typename T>
Array<T> :: Array() {
	_size = 0;
	_array = NULL;
}

template <typename T>
Array<T> :: ~Array() {
	if(_size)
	delete[] Array<T> ::_array;
}

template <typename T>
Array<T> :: Array(unsigned int n) {
	_size = n;
	_array = new T[n];
}

template <typename T>
Array<T> :: Array(const Array & for_copy) {
	_array = new T[for_copy._size];
	_size = for_copy._size;
	for(size_t i = 0; i < for_copy._size; ++i) {
		_array[i] = for_copy._array[i];
	}
}

template <typename T>
Array<T> & Array<T> :: operator = (const Array & for_assign) {
	if(this == &for_assign)
		return(*this);
	if(_size)
		delete[] _array;
	Array<T> ::_array = new T[for_assign._size];
	for(size_t i = 0; i < for_assign._size; ++i) {
		Array<T> :: _array[i] = for_assign._array[i];
	}
	return(*this);
}

template <typename T>
const char* Array<T> :: ArrayIndexError :: what() const throw() {
		return ("Bad index value");
}

template <typename T>
T & Array<T> :: operator [] (size_t idx) {
	if(idx >= _size)
		throw ArrayIndexError();
	return (_array[idx]);
}

template <typename T>
size_t Array<T> :: size() const {
	return (_size);
}

#endif