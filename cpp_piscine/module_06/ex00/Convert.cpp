/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:35:47 by utygett           #+#    #+#             */
/*   Updated: 2022/02/06 18:36:58 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert :: Convert() {
	_value = 0;
}

Convert :: ~Convert() {
}

Convert :: Convert(std :: string str) {
	if (str.size() == 1 && !isdigit(str[0]) ){
		_value = static_cast <double> (str[0]);
	} else 
		_value = static_cast <double> (stod(str));
}

Convert :: Convert(const Convert & for_copy) {
	_value = for_copy._value;
}

Convert & Convert :: operator = (const Convert & for_assign) {
	if(this == &for_assign)
		return (*this);
	_value = for_assign._value;
	return (*this);
	
}

void Convert :: writetoChar() {
	std::cout << "char: ";
	if (!isascii(_value)) {
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (!isprint(_value))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast <char> (_value) << "'" << std::endl;
}

void Convert :: writetoInt() {
	std :: cout << "int: ";
	if (_value > std :: numeric_limits <int>::max() || _value < std :: numeric_limits <int>::min() || _value != _value) {
		std :: cout << "impossible" << std :: endl;
		return ;
	}
	std::cout << static_cast <int> (_value) << std :: endl;
	
}

void Convert :: writetoFloat() {
	std::cout << "float: ";
	if (_value == std::numeric_limits <double>::infinity() || _value == -std::numeric_limits <double>::infinity() || std::numeric_limits<float>::quiet_NaN()){
		std::cout <<static_cast <float>(_value) << 'f' <<std::endl;
		return ;
	}
	if (_value > std::numeric_limits <float>::max() || _value < -std::numeric_limits <float>::max()) {
		std::cout << "impossible" << std::endl;
		return ;
	}

	std::cout << static_cast <float> (_value) << std::endl;

}

void Convert :: writetoDouble() {
	std::cout << "double: ";
	if (_value == std::numeric_limits <double>::infinity() || _value == -std::numeric_limits <double>::infinity() || std::numeric_limits<double>::quiet_NaN()) {
		std::cout << _value << std::endl;
		return ;
	}
	if (_value > std::numeric_limits <double>::max() || _value < -std::numeric_limits <double>::max()) {
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << static_cast <double> (_value) << std::endl;
}

