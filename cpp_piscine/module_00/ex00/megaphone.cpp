/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:03:03 by utygett           #+#    #+#             */
/*   Updated: 2022/01/11 15:24:00 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	std :: string str;
	if (argc == 1)
	{
		std :: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" <<std :: endl;
		return (0);
	}
	else
	{
		for(int j = 0; j < argc - 1 ; j++)
		{
			str = argv[j + 1];
			for (size_t i = 0; i < str.size(); i++)
			{
				str[i] = std :: toupper(str[i]);
			}
			std :: cout << str;
		}
	}
	std :: cout << std :: endl;
	return (0);
}