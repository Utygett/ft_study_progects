/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:32:21 by utygett           #+#    #+#             */
/*   Updated: 2022/02/15 13:38:51 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>
template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack(){}
	~MutantStack(){}
	MutantStack(const MutantStack & for_copy) : std::stack<T>(for_copy){}
	MutantStack & operator = (const MutantStack & for_assign){
		if(this != &for_assign){
			this->c = for_assign.c;
		}
		return(*this);
	}
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin() {
		return (this->c.begin());
	}
	iterator end() {
		return (this->c.end());
	}
};

#endif