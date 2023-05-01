/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:38:01 by utygett           #+#    #+#             */
/*   Updated: 2022/01/11 23:36:48 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <iostream>
#include <string>
#include <iomanip>

class Contact {
	
public:

	Contact();
	~Contact();

	std :: string get_first_name(void);
	std :: string get_last_name(void);
	std :: string get_nickname(void);
	size_t	get_phone_number(void);
	std :: string get_darkest_secret(void);
	

	void set_first_name(std :: string fname);
	void set_last_name(std :: string lname);
	void set_nickname(std :: string nick);
	void set_phone_number(size_t num);
	void set_darkest_secret(std :: string sec);


private:


	std :: string _first_name;
	std :: string _last_name;
	std :: string _nickname;
	size_t _phone_number;
	std :: string _darkest_secret;
	
};

class Phonebook {
	
public:

	Phonebook();
	~Phonebook();
	Contact get_contact( int index );
	void set_contact( Contact cont, int index );
private:
	Contact base[8];	

};

# endif