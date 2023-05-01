/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:57 by utygett           #+#    #+#             */
/*   Updated: 2022/02/06 12:04:42 by utygett          ###   ########.fr       */
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
	const int _gradeForSign;
	const int _gradeForExecute;
	int checkGrade(int grade);
protected:
	virtual void completeExecute() const = 0;
public:
	Form();
	virtual ~Form();
	Form(std :: string name, int gradeForSign, int gradeForExecute);
	Form(const Form & for_copy);
	Form & operator = (const Form & for_assign);
	std :: string getName(void) const; 
	bool getSigned(void) const;
	int getGradeForExecute(void) const;
	int getGradeForSign(void) const;
	void beSigned(const Bureaucrat & for_signed);
	void execute(Bureaucrat const & executor) const;
	class GradeTooHighException : public std :: exception {
		virtual const char* what() const throw();
	};
	class FormNotSignException : public std :: exception {
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std :: exception {
		virtual const char* what() const throw();
	}; 
};
std :: ostream & operator << (std :: ostream & o, Form const & for_stream);




#endif