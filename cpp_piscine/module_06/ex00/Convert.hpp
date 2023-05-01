/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:22:34 by utygett           #+#    #+#             */
/*   Updated: 2022/02/06 18:37:24 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERCHAR_HPP
# define CONVERCHAR_HPP

#include <string>
#include <iostream>
class Convert
{
private:
	double _value;
public:
	Convert();
	~Convert();
	Convert(std :: string str);
	Convert(const Convert & for_copy);
	Convert & operator = (const Convert & for_assign);
	void writetoChar();
	void writetoInt();
	void writetoFloat();
	void writetoDouble();
};


#endif