/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:51:03 by utygett           #+#    #+#             */
/*   Updated: 2022/02/06 13:15:17 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern :: Intern() {
	Intern :: f [0] = &Intern :: makeRobotomy;
	Intern :: f [1] = &Intern :: makePresidential;
	Intern :: f [2] = &Intern :: makeShrubbery;
}

Intern :: ~Intern() {
	
}

Intern :: Intern(const Intern & for_copy) {
	*this = for_copy;
}

Intern & Intern :: operator= (const Intern & for_assign) {
	if(this == &for_assign)
		return (*this);
	return (*this);
}

Form* Intern :: makeRobotomy(const std::string & target) const {
	return (new RobotomyRequestForm(target));

}
Form* Intern :: makePresidential(const std::string & target) const {
	return (new PresidentialPardonForm(target));

}
Form* Intern :: makeShrubbery(const std::string & target) const {
		return (new ShrubberyCreationForm(target));
}

Form* Intern ::makeForm(const std::string & name, const std::string & target) const {
	std :: string forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	int i = 0;
	while (i < 3 && name != forms[i])
		i++;
	enum {ROBOTOMY, PRESIDENT, SHRUBBERY};
	switch (i)
	{
	case ROBOTOMY:
		std :: cout << "Intern creates " << forms[ROBOTOMY] << std :: endl;
		return ((this->*(f[i]))(target));
	case PRESIDENT:
		std :: cout << "Intern creates " << forms[PRESIDENT] << std :: endl;
		return ((this->*(f[i]))(target));
	case SHRUBBERY:
		std :: cout << "Intern creates " << forms[SHRUBBERY] << std :: endl;
		return ((this->*(f[i]))(target));
	default:
		std :: cout << "Intern  can't create [" << name << "] because his don't know this form." << std :: endl;
		return NULL;
	}
	return (NULL);
}