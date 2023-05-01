/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:38:02 by utygett           #+#    #+#             */
/*   Updated: 2022/01/14 21:12:18 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "contact.hpp"

Phonebook  :: Phonebook () {
	
	return ;
}

Phonebook  :: ~Phonebook () {
	
	return ;
}

Contact :: Contact() {
	
	return ;
}

Contact :: ~Contact() {
	
	return ;
}

size_t Contact :: get_phone_number() {

	return this->_phone_number;
}

std :: string Contact :: get_first_name() {

	return this->_first_name;
}

std :: string Contact :: get_last_name() {

	return this->_last_name;
}

std :: string Contact :: get_nickname() {

	return this->_nickname;
}

std :: string Contact :: get_darkest_secret() {

	return this->_darkest_secret;
}

void Contact :: set_first_name(std :: string str){

	this->_first_name = str;
	return ;
}

void Contact :: set_last_name (std :: string str){

	this->_last_name = str;
	return ;
}

void Contact :: set_nickname (std :: string str){

	this->_nickname = str;
	return ;
}

void Contact :: set_darkest_secret (std :: string str){

	this->_darkest_secret = str;
	return ;
}

void Contact :: set_phone_number (size_t num){

	this->_phone_number = num;
	return ;
}

Contact Phonebook :: get_contact ( int index) {
	return this->base[index];
}

void Phonebook :: set_contact ( Contact cont, int index) {
	this->base[index] = cont;
	return ;
}

