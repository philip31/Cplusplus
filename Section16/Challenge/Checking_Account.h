#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include <iostream>
#include <string>
#include "Account.h"

class Checking_Account: public Account {
    //friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double per_check_fee = 1.5;
public:
    Checking_Account(std::string name = def_name, double balance = def_balance);    
    virtual bool withdraw(double) override;
    virtual bool deposit(double) override;
    // Inherits the Account::deposit method
    ~Checking_Account() { cout << "Checking Account destructor called" << endl; }
    void print(std::ostream &os) const override { os << "[ type: Checking Account, name:" << name << ", balance: " << balance << ", check fee: " << per_check_fee << " ]" << std::endl; }
};

#endif // _CHECKING_ACCOUNT_H_
