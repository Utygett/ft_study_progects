/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:19:03 by utygett           #+#    #+#             */
/*   Updated: 2022/05/07 19:25:40 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
#include "utils.hpp"
#include <memory>
namespace ft
{
	template <class It>
	class  reverse_iterator
	{
	public:
		typedef It														iterator_type;
		typedef typename	ft::iterator_traits<It>::difference_type	difference_type;
		typedef typename	ft::iterator_traits<It>::value_type			value_type;
		typedef typename	ft::iterator_traits<It>::pointer			pointer;
		typedef typename	ft::iterator_traits<It>::reference			reference;
		typedef typename	ft::iterator_traits<It>::iterator_category	iterator_category;
		reverse_iterator(): current(It()) {}
		explicit reverse_iterator (iterator_type it):current(it){}
		template <class Iter>
  		reverse_iterator (const reverse_iterator<Iter>& rev_it): current(rev_it.base()) {}
		~reverse_iterator(){}
		template <class Iter>
		reverse_iterator& operator=(const reverse_iterator<Iter>& u) { current = u.base(); return *this; }
		iterator_type base() const {return current;}
		reference operator*() const {It tmp = current; return *--tmp;}
		pointer  operator->() const {return std::addressof(operator*());}
		 reverse_iterator& operator++() {--current; return *this;}
		reverse_iterator  operator++(int) {reverse_iterator tmp(*this); --current; return tmp;}
		reverse_iterator& operator--() {++current; return *this;}
		reverse_iterator  operator--(int) {reverse_iterator tmp(*this); ++current; return tmp;}
		reverse_iterator  operator+ (difference_type n) const {return reverse_iterator(current - n);}
		reverse_iterator& operator+=(difference_type n) {current -= n; return *this;}
		reverse_iterator  operator- (difference_type n) const {return reverse_iterator(current + n);}
		reverse_iterator& operator-=(difference_type n) {current += n; return *this;}
		reference         operator[](difference_type n) const {return *(*this + n);}
	protected:
        iterator_type current;
	};
	template <class It1, class It2>
	bool	operator==(const reverse_iterator<It1>& x, const reverse_iterator<It2>& y) {
		return x.base() == y.base();
	}

	template <class It1, class It2>
	bool	operator<(const reverse_iterator<It1>& x, const reverse_iterator<It2>& y) {
		return x.base() > y.base();
	}

	template <class It1, class It2>
	bool	operator!=(const reverse_iterator<It1>& x, const reverse_iterator<It2>& y) {
		return x.base() != y.base();
	}

	template <class It1, class It2>
	bool	operator>(const reverse_iterator<It1>& x, const reverse_iterator<It2>& y) {
		return x.base() < y.base();
	}

	template <class It1, class It2>
	bool	operator>=(const reverse_iterator<It1>& x, const reverse_iterator<It2>& y) {
		return x.base() <= y.base();
	}

	template <class It1, class It2>
	bool	operator<=(const reverse_iterator<It1>& x, const reverse_iterator<It2>& y) {
		return x.base() >= y.base();
	}

	template <class It1, class It2>
	typename reverse_iterator<It1>::difference_type
	operator-(const reverse_iterator<It1>& x, const reverse_iterator<It2>& y) {
		return y.base() - x.base();
	}

	template <class It>
	reverse_iterator<It>
	operator+(typename reverse_iterator<It>::difference_type n, const reverse_iterator<It>& x) {
		return reverse_iterator<It>(x.base() - n);
	}
}

#endif