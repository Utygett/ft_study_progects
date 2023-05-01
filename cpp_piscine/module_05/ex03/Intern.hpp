/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:51:01 by utygett           #+#    #+#             */
/*   Updated: 2022/02/06 12:37:02 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include "Form.hpp"

class	Intern
{
private:
	Form *(Intern :: *f[3])( const std::string& target ) const;
public:
	Intern();
	virtual ~Intern();
	Intern(const Intern& other);
	Intern&	operator= (const Intern& other);
	Form *makeRobotomy(const std::string& target) const;
	Form *makePresidential(const std::string& target) const;
	Form *makeShrubbery(const std::string& target) const;
	Form *makeForm(const std::string& name, const std::string& target) const;
};

#endif