/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:38:26 by utygett           #+#    #+#             */
/*   Updated: 2022/02/05 14:04:10 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat :: Bureaucrat() : _name("Default") {
	_grade = MIN_GRADE;
}
Bureaucrat :: Bureaucrat(std :: string name, int grade) : _name(name) {
		if (grade > MIN_GRADE) {
			throw Bureaucrat :: GradeTooLowException();
		}
		else if (grade < MAX_GRADE){
			throw Bureaucrat :: GradeTooHighException();
		}
		_grade = grade;
}

Bureaucrat :: ~Bureaucrat() {
}

Bureaucrat :: Bureaucrat(const Bureaucrat & for_copy) : _name(for_copy.getName()), _grade(for_copy.getGrade()) {
}

Bureaucrat & Bureaucrat :: operator = (const Bureaucrat & for_assign) {
	if(this == &for_assign)
		return (*this);
	this->_grade = for_assign.getGrade();
	return(*this);
	
}

std :: string Bureaucrat :: getName(void) const {
	return (_name);
}

void Bureaucrat :: incrementGrade(void){
		if(_grade > 1)
			--_grade;
		else 
			throw Bureaucrat :: GradeTooHighException();
		
}

void Bureaucrat :: decrementGrade(void){

		if(_grade < 150)
			++_grade;
		else 
			throw Bureaucrat :: GradeTooLowException();
}

int Bureaucrat :: getGrade(void) const{
	return (_grade);
}

const char* Bureaucrat :: GradeTooHighException :: what() const throw(){
	return "Can't grade high, 1 is maximum grade.";
}

const char* Bureaucrat :: GradeTooLowException :: what() const throw(){
	return "Can't grade low, 150 is minimum grade.";
}

std :: ostream & operator << (std :: ostream & o, Bureaucrat const & for_stream) {
	o << for_stream.getName() << ", bureaucrat grade " << for_stream.getGrade();
	return (o);
}