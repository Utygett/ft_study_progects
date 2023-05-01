/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:32:03 by utygett           #+#    #+#             */
/*   Updated: 2022/01/18 13:02:06 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv) {
	if (argc != 4) {
		std :: cout << "Error, needs three argumets" << std :: endl;
		return (1);
	}
	std :: string filename(argv[1]);
	std :: ifstream input(filename);
	if(!input){
		std :: cout << "Something wrong with file " << std :: endl;
		return 1;
	}
	std :: string s1(argv[2]);
	std :: string s2(argv[3]);
	std :: ofstream output(filename.append(".replace"));
    std :: string str;                        
    std :: string str1;                        

	int pos = 0;
	
	while(std :: getline(input, str1)) {
		str += str1;
		str += '\n';
	}
	str.pop_back();
	while(pos != -1) {
		pos = str.find(s1, pos);
		if (pos != -1){
			str.erase(pos, s1.size());
			str.insert(pos, s2);
		}
	}
	output << str;
	output.close();
    input.close();                         
    return (0);
	
}
