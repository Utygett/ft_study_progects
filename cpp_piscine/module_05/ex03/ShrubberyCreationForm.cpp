/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:27:22 by utygett           #+#    #+#             */
/*   Updated: 2022/02/05 17:19:30 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
ShrubberyCreationForm :: ShrubberyCreationForm() : Form ::Form("ShrubberyCreationForm", _gradeForSign, _gradeForExecute), _target("Default") {
}

ShrubberyCreationForm :: ~ShrubberyCreationForm() {
}

ShrubberyCreationForm :: ShrubberyCreationForm(std :: string target) : Form :: Form("ShrubberyCreationForm", _gradeForSign, _gradeForExecute), _target(target) {

}

ShrubberyCreationForm :: ShrubberyCreationForm(const ShrubberyCreationForm & for_copy) : Form :: Form("ShrubberyCreationForm", _gradeForSign, _gradeForExecute),  _target(for_copy._target){

}

ShrubberyCreationForm & ShrubberyCreationForm ::operator = (const ShrubberyCreationForm & for_assign) {
	if(this == &for_assign)
		return (*this);
	_target = for_assign._target;
	return (*this);
}

void ShrubberyCreationForm :: completeExecute() const {
	std::ofstream	outfile(_target + "_shrubbery");
	if (!outfile) {
		std::cout << "Error occured while creating a new file" << std::endl;
		throw std::exception();
	}
	outfile << "       _-_" << std::endl
			<< "    /~~   ~~\\" << std::endl
			<< " /~~         ~~\\" << std::endl
			<< "{               }" << std::endl
			<< " \\  _-     -_  /" << std::endl
			<< "   ~  \\\\ //  ~" << std::endl
			<< "_- -   | | _- _" << std::endl
			<< "  _ -  | |   -_" << std::endl
			<< "      // \\\\" << std::endl;
}