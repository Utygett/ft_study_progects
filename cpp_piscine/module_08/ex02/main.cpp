/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:29:15 by utygett           #+#    #+#             */
/*   Updated: 2022/02/15 14:40:47 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main () {
	{
		std::cout << "Subject test" << std::endl;

		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
		
		std::cout << "My test copy constructor" << std::endl;
		MutantStack<int> mstack1(mstack);
		while (!mstack1.empty())
		{
			std::cout << mstack1.top() << std::endl;
			mstack1.pop();
		}
		std::cout << "My test assign operator" << std::endl;
		MutantStack<int> mstack2;
		mstack2 = mstack;
		while (!mstack2.empty())
		{
			std::cout << mstack2.top() << std::endl;
			mstack2.pop();
		}
	}
	{
		std::cout << "My test member function" << std::endl;
		MutantStack<int> s1, s2;
		s1.push(1);
		if (s1.empty())
			std::cout << "The stack s1 is empty." << std::endl;
		else
			std::cout << "The stack s1 is not empty." << std::endl;
		if (s2.empty())
			std::cout << "The stack s2 is empty." << std::endl;
		else
			std::cout << "The stack s2 is not empty." << std::endl;
		s1.push(10);
		s1.push(20);
		s1.push(30);
		std::cout << "The stack length is " <<  s1.size( ) << "." << std::endl;
		std::cout << "The element at the top of the stack is "
				  << s1.top() << "." << std::endl;
		s1.pop( );
		std::cout << "After a pop, the stack length is "
				  << s1.size() << "." << std::endl;
		std::cout << "After a pop, the element at the top of the stack is "
				<< s1.top() << "." << std::endl;
	}
	{
		std::cout << "Subject test std::list" << std::endl;

		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
	}
	return 0;
}