#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main() {
    // test your code here
    try {
        Account *ptr = new Savings_Account{"nume", 5};
        ptr->withdraw(10);
    }
    catch(IllegalBalanceException &ex) {
        cout << ex.what() << endl;
    }
    catch(InsufficentFundsException &ex) {
        cout << ex.what() << endl;
    }
    std::cout << "Program completed successfully" << std::endl;
    return 0;
}

