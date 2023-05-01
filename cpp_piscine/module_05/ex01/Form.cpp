/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:59 by utygett           #+#    #+#             */
/*   Updated: 2022/02/05 15:01:57 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form :: Form() : _name("Default"), _gradeForExecute(MIN_GRADE), _gradeForSign(MIN_GRADE) {
	_signed = false;
}

Form :: ~Form() {
}

Form :: Form(std :: string name, int gradeForExecute, int gradeForSign) : _name(name), _gradeForExecute(checkGrade(gradeForExecute)), _gradeForSign(checkGrade(gradeForSign)) {
	_signed = false;
}

int Form :: checkGrade(int grade) {
	if (grade > MIN_GRADE) {
		throw Form :: GradeTooLowException();
	}
	else if (grade < MAX_GRADE){
		throw Form :: GradeTooHighException();
	}
	return (grade);
}

Form :: Form(const Form & for_copy) : _name(for_copy.getName()), _signed(for_copy.getSigned()), _gradeForExecute(for_copy.getGradeForExecute()), _gradeForSign(for_copy.getGradeForSign()) {
}

Form & Form :: operator = (const Form & for_assign) {
	if(this == &for_assign)
		return (*this);
	_signed = for_assign.getSigned();
	return (*this);
}

std :: string Form :: getName(void) const {
	return (_name);
}

bool Form :: getSigned(void) const {
	return (_signed);
}

int Form :: getGradeForExecute(void) const {
	return (_gradeForExecute);
}
int Form ::getGradeForSign(void) const {
	return (_gradeForSign);
}


void Form :: beSigned(const Bureaucrat & for_signed) {
	if (_signed)
		return ;
	else if (_gradeForExecute >= for_signed.getGrade())
		_signed = true;
	else {
		throw Form :: GradeTooLowException();
	}
}

const char* Form :: GradeTooHighException :: what() const throw() {
	return "Grade it's too high.";
}

const char* Form :: GradeTooLowException :: what() const throw() {
	return "Grade it's too low.";
}

std :: ostream & operator << (std :: ostream & o, Form const & for_stream) {
	o << "Form " <<for_stream.getName();
	if(for_stream.getSigned())
		o << " signed.";
	else
		o << " not signed.";
	o << " Grade need for singned is " << for_stream.getGradeForSign();
	o << ". Grade need for execute is " << for_stream.getGradeForExecute();
	return (o);
}