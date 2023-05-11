#include <iostream>

using namespace std;

int main(){
    int number;
    cout << "Enter an amount in pennies: ";
    cin >> number;
    
    const int dollar_value {100}, quarter_value {25}, dime_value {10}, nickel_value {5};
    int dollars {}, quarters {}, dimes {}, nickels {}, pennies {};
    
    dollars = number / dollar_value;
    number %= dollar_value;
    
    quarters = number / quarter_value;
    number %= quarter_value;
    
    dimes = number / dime_value;
    number %= dime_value;
    
    nickels = number / nickel_value;
    number %= nickel_value;
    
    pennies = number;
    
    
    cout << "The change that can be provided:" << endl;
    cout << "dollars: " << dollars << endl;
    cout << "quarters: " << quarters << endl;
    cout << "dimes: " << dimes << endl;
    cout << "nickels: " << nickels << endl;
    cout << "pennies: " << pennies << endl;
    
}
