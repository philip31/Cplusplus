#ifndef TRUST_ACCOUNT_HPP
#define TRUST_ACCOUNT_HPP
#include "Savings_Account.hpp"

class Trust_Account : public Savings_Account
{
    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
public:
    int nr_withdrawl;
    
    Trust_Account(std::string name = "Unnamed Account", double balance = 0.0, double int_rate = 0.0);
    ~Trust_Account();

    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif // TRUST_ACCOUNT_HPP
