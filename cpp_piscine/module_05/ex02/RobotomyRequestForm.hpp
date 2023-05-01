/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:27:21 by utygett           #+#    #+#             */
/*   Updated: 2022/02/05 17:12:06 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
#include "Form.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form
{
private:
	std :: string _target;
	virtual void completeExecute() const;
	static const int _gradeForSign = 25;
	static const int _gradeForExecute = 5;
public:
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(std :: string target);
	RobotomyRequestForm(const RobotomyRequestForm & for_copy);
	RobotomyRequestForm & operator = (const RobotomyRequestForm & for_assign);
};

#endif