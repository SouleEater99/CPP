#include "./Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    _amount = initial_deposit;
    _accountIndex = _nbAccounts;
    _displayTimestamp();
    std::cout << " index:" <<  _accountIndex <<  ";amount:" <<  _amount <<  ";created\n";
    _nbAccounts++;
    _totalAmount += initial_deposit;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" <<  _accountIndex <<  ";amount:" <<  _amount <<  ";closed\n";
}

int Account::getNbAccounts()    {return _nbAccounts;}
int Account::getTotalAmount()   {return _totalAmount;}
int Account::getNbDeposits()    {return _totalNbDeposits;}
int Account::getNbWithdrawals() {return _totalNbWithdrawals;}

void    Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << " accounts:" <<  _nbAccounts <<  ";total:" <<  _totalAmount <<  ";deposits:" <<  _totalNbDeposits;
    std::cout << ";withdrawals:" <<  _totalNbWithdrawals <<  "\n";
}


void	Account::makeDeposit( int deposit )
{
    int pervious_amount;

    pervious_amount = _amount;
    _nbDeposits++;
    _totalNbDeposits++;
    _amount += deposit;
    _totalAmount += deposit;
    _displayTimestamp();
    std::cout << " index:" <<  _accountIndex <<  ";p_amount:" <<  pervious_amount <<  ";deposits:" <<  deposit;
    std::cout << ";amount:"<< _amount <<  ";nb_deposits:" <<  _nbDeposits <<  "\n";
}

int     Account::checkAmount() const {return _amount;}

bool	Account::makeWithdrawal( int withdrawal)
{
    int pervious_amount;

    _displayTimestamp();
    if (withdrawal <= 0 || withdrawal > _amount)
    {
        std::cout << " index:" <<  _accountIndex <<  ";p_amount:" <<  _amount <<  ";withdrawal:refused\n";
        return false;
    }
    pervious_amount = _amount;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    std::cout << " index:" << _accountIndex << ";p_amount:" << pervious_amount << ";withdrawal:" << withdrawal;
    std::cout << ";amount:"<< _amount << ";nb_withdrawals:" << _nbWithdrawals << "\n";
    return true;
}

void    Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << " index:" <<  _accountIndex <<  ";amount:" <<  _amount;
    std::cout << ";deposits:" << _nbDeposits  << ";withdrawal:" <<  _nbWithdrawals <<  "\n";
}

void    Account::_displayTimestamp()
{
    char    buffer[20];

    std::time_t now = std::time(0);
    std::tm     *ltm = std::localtime(&now);

    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", ltm);
    std::cout << buffer ;
}
