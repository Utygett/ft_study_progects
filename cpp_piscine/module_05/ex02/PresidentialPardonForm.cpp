/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:27:16 by utygett           #+#    #+#             */
/*   Updated: 2022/02/05 17:18:21 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm :: PresidentialPardonForm() : Form ::Form("PresidentialPardonForm", _gradeForSign, _gradeForExecute), _target("Default") {
}

PresidentialPardonForm :: ~PresidentialPardonForm() {
}

PresidentialPardonForm :: PresidentialPardonForm(std :: string target) : Form :: Form("PresidentialPardonForm", _gradeForSign, _gradeForExecute), _target(target) {

}

PresidentialPardonForm :: PresidentialPardonForm(const PresidentialPardonForm & for_copy) : Form :: Form("PresidentialPardonForm", _gradeForSign, _gradeForExecute), _target(for_copy._target){

}

PresidentialPardonForm & PresidentialPardonForm ::operator = (const PresidentialPardonForm & for_assign) {
	if(this == &for_assign)
		return (*this);
	_target = for_assign._target;
	return (*this);
}

void PresidentialPardonForm :: completeExecute() const {
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

