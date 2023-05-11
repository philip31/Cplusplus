#include <iostream>
#include <string>

using namespace std;

int main(){
    
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key      {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
    
    string message {};
    
    cout << "write a message to encrypt: ";
    getline(cin, message);
    
    for (size_t i; i < message.length(); ++i)
    {
        size_t position = alphabet.find(message.at(i));
        if (position != string::npos)
        {
            message.at(i) = key.at(position);
        }
    }
    
    cout << "Encrypting the message.." << endl;
    cout << "The encrypted message is : " + message << endl;
    
    
    return 0;
}
