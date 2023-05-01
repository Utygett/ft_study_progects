/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:27:24 by utygett           #+#    #+#             */
/*   Updated: 2022/02/05 17:12:48 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
#include "Form.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form
{
private:
	std :: string _target;
	virtual void completeExecute() const;
	static const int _gradeForSign = 145;
	static const int _gradeForExecute = 137;
public:
	ShrubberyCreationForm();
	~ShrubberyCreationForm();
	ShrubberyCreationForm(std :: string target);
	ShrubberyCreationForm(const ShrubberyCreationForm & for_copy);
	ShrubberyCreationForm & operator = (const ShrubberyCreationForm & for_assign);
};

#endif