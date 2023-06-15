#include "Checking_Account.hpp"

Checking_Account::Checking_Account(std::string name, double balance)
    : Account::Account{name, balance}
{
}

Checking_Account::~Checking_Account()
{
}

bool Checking_Account::withdraw(double amount) {
    return Account::withdraw(amount + fee);
}

std::ostream &operator<<(std::ostream &os, const Checking_Account &account) {
    os << "[Account: " << account.name << ": " << account.balance << " fee: " << account.fee << "]";
    return os; 
}
