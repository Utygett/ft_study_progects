/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:23:05 by utygett           #+#    #+#             */
/*   Updated: 2022/01/14 21:07:57 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

std :: string prepare_write(std :: string str)
{
	if (str.size() <= 10)
		return (str);
	str[9] = '.';
	return (str.substr(0,10));
}

void write_tips( void ) {
	std :: cout << "Please use the next commadns."<< std :: endl
				<< "ADD    : for add a new contact." << std :: endl
				<< "SEARCH : for searching contacts." << std :: endl
				<< "EXIT   : for exit." << std :: endl;
}

int main()
{
	int	num;
	size_t phone_number;
	int	index;
	Phonebook phone;
	Contact buf;
	std :: string str;
	
	write_tips();
	num = 0;
	while(1)
	{
		std :: cin >> str;
		if(!std ::cin)
			return (0);
		if(str.compare("ADD") == 0)
		{
			if(num > 7)
			{
				for(int i = 0; i < num - 1; i++)
				{
					phone.set_contact(phone.get_contact(i + 1), i);
				}
				num = 7;
			}
			std :: cout << "First name: ";
			std :: cin >> str;
			buf.set_first_name(str);
			std :: cout << "Last name: ";
			std :: cin >> str;
			buf.set_last_name(str);
			std :: cout << "Nickname: ";
			std :: cin >> str;
			buf.set_nickname(str);
			std :: cout << "Phone number: ";
			while (1)
			{
				std :: cin >> str;
				if(!std ::cin)
					return (0);
				if (isdigit(str[0]) && str.size() < 12)
				{
					phone_number = std :: stol(str);
					break ;
				}
				else {
					phone_number = 0;
					std :: cout << "Invalid phone number, please write correct number." << std :: endl;
					std :: cout << "Phone number: ";
				}
			}
			buf.set_phone_number(phone_number);
			std :: cout << "Darkest secret: ";
			std :: cin >> str;
			buf.set_darkest_secret(str);
			std :: cout << "Contact added." << std :: endl;
			phone.set_contact(buf, num);
			num++;
		}
		else if(str.compare("SEARCH") == 0)
		{
			if (num == 0) {
				std :: cout << "There is no contact, please add at least one." << std :: endl;
				continue ;
			}
			std :: cout << std :: setw(10)
						<< "index" << "|"
						<< std ::setw(10)
						<< "first name" << "|"
						<< std ::setw(10)
						<< "last name" << "|"
						<< std ::setw(10)
						<< "nickname" << "\n";

			for(int i = 0; i < num; i++)
			{
				std :: cout << std :: right << std ::setw(10) << i + 1 << "|"
							<< std ::setw(10) << prepare_write(phone.get_contact(i).get_first_name()) << "|"
							<< std ::setw(10) << prepare_write(phone.get_contact(i).get_last_name()) << "|"
							<< std ::setw(10) << prepare_write(phone.get_contact(i).get_nickname())  << std :: endl;
			}
			std :: cout << "Write index the contact : ";
			std :: cin >> str;
			if (isdigit(str[0]) && str.size() == 1)
				index = std :: stoi(str);
			else
				index = -1;
			index -= 1;
			if (index + 1 > 0 && index < num)
			{
				std :: cout << std :: setw(15) << std :: left << "First name" << ":" << phone.get_contact(index).get_first_name() << std :: endl
							<< std :: setw(15) << "Last name"<< ":" << phone.get_contact(index).get_last_name() << std :: endl
							<< std :: setw(15) << "Nickname"<< ":" << phone.get_contact(index).get_nickname() << std :: endl
							<< std :: setw(15) << "Phone number"<< ":" << phone.get_contact(index).get_phone_number() << std :: endl
							<< std :: setw(15) << "Darkest secret"<< ":" << phone.get_contact(index).get_darkest_secret() << std :: endl;
			}
			else
				std :: cout << "The index of this contact does not exist." << std :: endl;
		}
		else if(str.compare("EXIT") == 0)
			return (0);
		else
			write_tips();
	}
}