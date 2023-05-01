/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 21:54:27 by utygett           #+#    #+#             */
/*   Updated: 2022/01/14 17:50:53 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <time.h>
#include <iomanip>
#include "Account.hpp"

int Account :: _nbAccounts = 0;
int Account :: _totalAmount = 0;
int Account :: _totalNbDeposits = 0;
int Account :: _totalNbWithdrawals = 0;

void Account :: _displayTimestamp( void ) {
	time_t current_time = time( NULL );
    struct tm *clock = localtime(&current_time);
    std::cout << '[' << clock->tm_year + 1900
	<< std :: setw(2) << std :: setfill('0') << clock->tm_mon + 1
	<< std :: setw(2) << std :: setfill('0') << clock-> tm_mday << "_"
    << std :: setw(2) << std :: setfill('0') << clock->tm_hour
	<< std :: setw(2) << std :: setfill('0') << clock->tm_min
	<< std :: setw(2) << std :: setfill('0') << clock->tm_sec << "] ";
}

Account :: Account( int initial_deposit ) {
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = _nbAccounts;
	Account :: _totalAmount += initial_deposit;
	Account :: _nbAccounts++;
	Account :: _displayTimestamp();
	std :: cout << "index:" << this->_accountIndex<< ";"
	<< "amount:" << this->_amount
	<< ";" << "created" << std :: endl;
	return ;
}
Account :: ~Account( void ) {
	Account :: _displayTimestamp();
	std :: cout << "index:" << this->_accountIndex << ";"
	<< "amount:" << this->_amount << ";"
	<< "closed" << std :: endl;
	Account :: _nbAccounts--;
	return ;
}
int Account :: getTotalAmount( void ) {
	return (Account :: _totalAmount);	
}

int Account :: getNbDeposits( void ) {
	return (Account :: _totalNbDeposits);
}

int Account :: getNbWithdrawals ( void ) {
	return (Account :: _totalNbWithdrawals);
}

void Account :: makeDeposit (int deposit) {
	Account :: _displayTimestamp();
	std :: cout << "index:" << this->_accountIndex << ";"
	<< "p_amount:" << this->_amount << ";"
	<< "deposit:" << deposit << ";" ;
	if(deposit < 0)
		deposit = 0;
	this->_amount += deposit;
	Account :: _totalAmount += deposit;
	Account :: _totalNbDeposits++;
	this->_nbDeposits++;
	std :: cout << "amount:" << this->_amount << ";"
	<< "nb_deposits:" << this->_nbDeposits << std :: endl;
	return ;
}

void Account :: displayStatus( void ) const {
	Account :: _displayTimestamp();
	std :: cout << "index:" << this->_accountIndex << ";"
	<< "amount:" << this->_amount << ";"
	<< "deposits:" << this->_nbDeposits << ";"
	<< "withdrawals:" << this->_nbWithdrawals << std :: endl;
	return ;
}

bool Account :: makeWithdrawal( int withdrawal ){
	Account :: _displayTimestamp();
	std :: cout << "index:" << this->_accountIndex << ";"
	<< "p_amount:" << this->_amount << ";"
	<< "withdrawal:" ;
	if(withdrawal > this->_amount)
	{
		std :: cout<< "refused" << std :: endl;
		return (false);
	}
	std :: cout<< withdrawal << ";" ;
	this->_amount -= withdrawal;
	Account :: _totalAmount -= withdrawal;
	Account :: _totalNbWithdrawals++;
	this->_nbWithdrawals++;
	std :: cout << "amount:" << this->_amount << ";"
	<< "nb_withdrawals:" << this->_nbWithdrawals << std :: endl;
	return (true);
}

void Account :: displayAccountsInfos( void ) {
	Account :: _displayTimestamp();
	std :: cout << "account:" << Account :: _nbAccounts << ";"
	<< "total:" << Account :: _totalAmount << ";"
	<< "deposits:" << Account :: _totalNbDeposits << ";"
	<< "withdrawals:" << Account :: _totalNbWithdrawals << std :: endl;
	return ;
}
