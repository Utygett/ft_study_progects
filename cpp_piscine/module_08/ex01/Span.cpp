/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:42:59 by utygett           #+#    #+#             */
/*   Updated: 2022/02/14 14:29:48 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <numeric>
Span::Span() {
	_maxSize = 0;
}
Span::~Span(){

}
Span::Span(unsigned int a){
	_maxSize = a;
}

Span::Span(const Span & for_copy) : _array(for_copy._array), _maxSize(for_copy._maxSize){
}

Span & Span::operator = (const Span & for_assign){
	std::cout << "assign" << std::endl;
	if (this != &for_assign) {
		_array = for_assign._array;
		_maxSize = for_assign._maxSize;
	}
	return (*this);

}

void Span::addNumber (int a){
	if (_array.size() < _maxSize)
		_array.push_back(a);
	else
		throw std::length_error("Can't add more objects, array is full");

}

int Span::shortestSpan(){
	if (_array.size() < 2)
		throw std::length_error("Error : Array size is small to call this function");
	std::sort(_array.begin(), _array.end());
	std::vector<int> buf(_maxSize);
	std::adjacent_difference(_array.begin(),_array.end(),buf.begin());
	return (*std::min_element(std::next(buf.begin()),buf.end()));
}

int Span::longestSpan(){
	if (_array.size() < 2)
		throw std::length_error("Error : Array size is small to call this function");
	return(*std::max_element(_array.begin(), _array.end()) - *std::min_element(_array.begin(), _array.end()));
}
