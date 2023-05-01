/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:53:39 by utygett           #+#    #+#             */
/*   Updated: 2022/01/17 20:33:36 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main( void ){
	Karen Cara;
	
	Cara.complain("DEBUG");
	Cara.complain("INFO");
	Cara.complain("WARNING");
	Cara.complain("ERROR");
	return (0);
}