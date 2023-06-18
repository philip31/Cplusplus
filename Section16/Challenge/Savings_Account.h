#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include "Account.h"
#include <iostream>

class Savings_Account: public Account {
    //friend std::ostream &operator<<(std::ostream &os, const Savings_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Savings Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
protected:
    double int_rate;
public:
    Savings_Account(std::string name = def_name, double balance =def_balance, double int_rate = def_int_rate);    
    virtual bool withdraw(double) override;
    virtual bool deposit(double) override;
    ~Savings_Account() { cout << "Savings Account destructor called" << endl; }
    void print(std::ostream &os) const override { os << "[ type: Savings Account, name:" << name << ", balance: " << balance << ", int rate: " << int_rate << " ]" << std::endl; }

};

#endif // _SAVINGS_ACCOUNT_H_
