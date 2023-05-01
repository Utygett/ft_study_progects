/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:53:39 by utygett           #+#    #+#             */
/*   Updated: 2022/01/18 13:02:53 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(int argc, char **argv){
	Karen Cara;
	if (argc != 2){
		std :: cout << "Error number of argumets." << std :: endl;
		return(1);
	}
	Cara.complain(argv[1]);
	return (0);
}
