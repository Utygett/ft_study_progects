/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:38:19 by utygett           #+#    #+#             */
/*   Updated: 2022/02/05 14:29:10 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "Form.hpp"
# define MAX_GRADE 1
# define MIN_GRADE 150
class Form;
class Bureaucrat
{
private:
	const std :: string _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(std :: string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat & for_copy);
	Bureaucrat & operator = (const Bureaucrat & for_assign);
	std :: string getName(void) const;
	void incrementGrade(void);
	void decrementGrade(void);
	int getGrade(void) const;
	void signForm(Form & for_signed);
	class GradeTooHighException : public std :: exception {
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std :: exception {
		virtual const char* what() const throw();
	}; 

};
std :: ostream & operator << (std :: ostream & o, Bureaucrat const & for_stream );

#endif