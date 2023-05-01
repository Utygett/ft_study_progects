/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:27:19 by utygett           #+#    #+#             */
/*   Updated: 2022/02/05 17:47:31 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm :: RobotomyRequestForm() : Form ::Form("RobotomyRequestForm", _gradeForSign, _gradeForExecute), _target("Default") {
}

RobotomyRequestForm :: ~RobotomyRequestForm() {
}

RobotomyRequestForm :: RobotomyRequestForm(std :: string target) : Form :: Form("RobotomyRequestForm", _gradeForSign, _gradeForExecute),  _target(target) {

}

RobotomyRequestForm :: RobotomyRequestForm(const RobotomyRequestForm & for_copy) : Form :: Form("RobotomyRequestForm", _gradeForSign, _gradeForExecute),  _target(for_copy._target) {

}

RobotomyRequestForm & RobotomyRequestForm ::operator = (const RobotomyRequestForm & for_assign) {
	if(this == &for_assign)
		return (*this);
	_target = for_assign._target;
	return (*this);
}

void RobotomyRequestForm :: completeExecute() const {
	srand (time(NULL));
	if (std :: rand() % 2)
		std :: cout << _target	<< " has been robotomized." << std::endl;
	else
		std :: cout << "Robotomy failed on " << _target << std::endl;
}