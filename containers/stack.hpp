/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 16:50:46 by utygett           #+#    #+#             */
/*   Updated: 2022/05/08 19:36:55 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP
#include <vector>
namespace ft
{
	template <class T, class Container = std::vector<T> >
	class stack
	{
	public:
		typedef Container                           container_type;
        typedef typename Container::value_type      value_type;
        typedef typename Container::size_type       size_type;

	protected:
		container_type c;

	public:
		stack(const stack& for_assign) : c(for_assign.c) {}
		explicit stack(const container_type& c = container_type()): c(c){}
		~stack(){}
		stack& operator=(const stack& for_assign) {
			c = for_assign.c;
			return *this;
		}
		bool empty() const {
			return c.empty();
		}
		size_type size() const {
			return c.size();
		}

		value_type&  top(){
			return c.back();
		}
		const   value_type& top() const {
			return c.back();
		}
		void push(const value_type& x) {
			c.push_back(x);
		}
		void pop() {
			c.pop_back();
		}
		bool operator==(const stack<T, Container>& y) {
		return this->c == y.c;
		}
		bool operator!=(const stack<T, Container>& y) {
			return this->c != y.c;
		}
		bool operator< (const stack<T, Container>& y) {
			return this->c < y.c;
		}
		bool operator> (const stack<T, Container>& y) {
			return this->c > y.c;
		}
		bool operator>=(const stack<T, Container>& y) {
			return this->c >= y.c;
		}
		bool operator<=(const stack<T, Container>& y) {
			return this->c <= y.c;
		}
	};
}
#endif