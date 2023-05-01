/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:24:48 by utygett           #+#    #+#             */
/*   Updated: 2022/02/14 17:38:58 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iterator>
#include <algorithm>

class Span {
private:
	std::vector<int> _array;
	unsigned int _maxSize;
public:
	Span();
	~Span();
	Span(unsigned int num);
	Span(const Span & for_copy);
	Span & operator = (const Span & for_assign);
	void addNumber (int num);
	int shortestSpan();
	int longestSpan();
	template <typename T>
	void fillSpan(T begin, T end) {
		if (std::distance(begin, end) +  _array.size() > _maxSize)
			throw std::length_error("Error : Can't fill the array");
		while (begin != end)
			addNumber(*begin++);
	};
};

#endif