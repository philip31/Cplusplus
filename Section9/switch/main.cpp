#include <iostream>
#include <typeinfo>
using namespace std;
 enum Color {
        red, blue, green
    };
enum Pseudo {
  zero, two, three  
};
int main(){


    
    int a {two};

    switch (a) {
        case red: cout << "red" << endl; break;
        case blue: cout << "blue" << endl; break;
        default: cout << "nothing"<< endl;
    }
    
    
    
    return 0;
}
