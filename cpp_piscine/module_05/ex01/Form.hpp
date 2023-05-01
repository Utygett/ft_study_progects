/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:57 by utygett           #+#    #+#             */
/*   Updated: 2022/02/05 15:55:52 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
private:
	const std :: string _name;
	bool _signed;
	const int _gradeForExecute;
	const int _gradeForSign;
	int checkGrade(int grade);
public:
	Form();
	~Form();
	Form(std :: string name, int gradeForExecute, int gradeForSign);
	Form(const Form & for_copy);
	Form & operator = (const Form & for_assign);
	std :: string getName(void) const; 
	bool getSigned(void) const;
	int getGradeForExecute(void) const;
	int getGradeForSign(void) const;
	void beSigned(const Bureaucrat & for_signed);
	class GradeTooHighException : public std :: exception {
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std :: exception {
		virtual const char* what() const throw();
	}; 
};
std :: ostream & operator << (std :: ostream & o, Form const & for_stream);




#endif