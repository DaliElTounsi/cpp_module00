#include <iostream>
#include "Account.hpp"

int main(void)
{
    Account a(100);

    a.displayStatus();
    a.makeDeposit(50);
    a.displayStatus();
    a.makeWithdrawal(1000);
    a.makeWithdrawal(30);
    a.displayStatus();
    Account::displayAccountsInfos();

    return 0;
}
