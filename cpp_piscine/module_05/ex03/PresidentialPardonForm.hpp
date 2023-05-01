/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:27:18 by utygett           #+#    #+#             */
/*   Updated: 2022/02/05 17:12:23 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
#include "Form.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form
{
private:
	std :: string _target;
	virtual void completeExecute() const;
	static const int _gradeForSign = 72;
	static const int _gradeForExecute = 45;
public:
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm(std :: string target);
	PresidentialPardonForm(const PresidentialPardonForm & for_copy);
	PresidentialPardonForm & operator = (const PresidentialPardonForm & for_assign);
};

#endif