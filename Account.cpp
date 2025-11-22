// ************************************************************************** //
//                                                                            //
//                Account.cpp for GlobalBanksters United                      //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstring>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp( void ) {
    std::time_t t = std::time(NULL);
    std::tm *tm = std::localtime(&t);
    char buf[32];
    if (tm)
        std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", tm);
    else
        std::strcpy(buf, "[00000000_000000] ");
    std::cout << buf;
}

int Account::getNbAccounts( void ) { return _nbAccounts; }
int Account::getTotalAmount( void ) { return _totalAmount; }
int Account::getNbDeposits( void ) { return _totalNbDeposits; }
int Account::getNbWithdrawals( void ) { return _totalNbWithdrawals; }

void Account::displayAccountsInfos( void ) {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals
              << std::endl;
}

Account::Account( int initial_deposit ) {
    this->_accountIndex = _nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";created" << std::endl;
    _nbAccounts++;
    _totalAmount += initial_deposit;
}

Account::~Account( void ) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";closed" << std::endl;
    _nbAccounts--;
    _totalAmount -= this->_amount;
}

void Account::makeDeposit( int deposit ) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << this->_amount
              << ";deposit:" << deposit;
    this->_amount += deposit;
    this->_nbDeposits += 1;
    _totalAmount += deposit;
    _totalNbDeposits += 1;
    std::cout << ";amount:" << this->_amount
              << ";nb_deposits:" << this->_nbDeposits
              << std::endl;
}

bool Account::makeWithdrawal( int withdrawal ) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << this->_amount
              << ";withdrawal:";
    if (withdrawal > this->_amount) {
        std::cout << "refused" << std::endl;
        return false;
    }
    this->_amount -= withdrawal;
    this->_nbWithdrawals += 1;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals += 1;
    std::cout << withdrawal
              << ";amount:" << this->_amount
              << ";nb_withdrawals:" << this->_nbWithdrawals
              << std::endl;
    return true;
}

int Account::checkAmount( void ) const {
    return this->_amount;
}

void Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";deposits:" << this->_nbDeposits
              << ";withdrawals:" << this->_nbWithdrawals
              << std::endl;
}
