#include "Trust_Account.hpp"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account {name, balance, int_rate}, nr_withdrawl {0}
{
}

Trust_Account::~Trust_Account()
{
}

bool Trust_Account::deposit(double amount) 
{
    if (amount >= 5000)
        amount += 50;
    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount) 
{
    if (nr_withdrawl >= 3)
        return false;
        
    if (amount > balance * 0.2)
        return false;
    
    balance -= amount;
    nr_withdrawl++;
    return true;
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
    return os; 
}
