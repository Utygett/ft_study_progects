/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:35:26 by utygett           #+#    #+#             */
/*   Updated: 2022/02/11 15:25:27 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array {
private:
	T *_array;
	size_t _size;
public:
	Array();
	~Array();
	Array(unsigned int n);
	Array(const Array & for_copy);
	Array & operator = (const Array & for_assign);
	
	class ArrayIndexError : public std :: exception {
		virtual const char* what() const throw();
	};
	T & operator [] (size_t idx);
	size_t size() const ;

};
# include "Array.tpp"
#endif