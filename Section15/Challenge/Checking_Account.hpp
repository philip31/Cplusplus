#ifndef CHECKING_ACCOUNT_HPP
#define CHECKING_ACCOUNT_HPP
#include "Account.hpp"

class Checking_Account : public Account
{
    friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);
private:
    static constexpr const double fee = 1.5;
public:
    Checking_Account(std::string name = "Unnamed Account", double balance = 0.0);
    ~Checking_Account();

    bool withdraw(double amount);

};

#endif // CHECKING_ACCOUNT_HPP
