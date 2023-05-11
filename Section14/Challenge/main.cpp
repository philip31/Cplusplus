#include <iostream>
#include <string>

using namespace std;

class Player {
private:
    string *name;
public:
    Player();
    Player(const string*);
    Player &operator=(const Player &);
    Player &operator=(Player &&);
    ~Player();
};

Player::Player(): name{nullptr} { cout << "Default constructor called" ;}

Player::Player(const string *s)
    : name{nullptr}
{
    cout << "Overloaded constructor called" << endl;
    if (s == nullptr)
        return;
    name = new string(*s);
    
}

Player::~Player()
{
    cout << "Destructor called for " << *name << endl;
    delete name;
}

Player &Player::operator=(const Player &rhs)
{
    cout << "Assignment copy operator called" << endl;
    
    if (this == &rhs)
        return *this;
        
    delete name;
    name = new string();
    name = rhs.name;
    return *this;
}

Player &Player::operator=(Player &&rhs)
{
    cout << "Assignment move operator called" << endl;
    
    if (this == &rhs)
        return *this;
        
    delete name;
    name = rhs.name;
    rhs.name = nullptr;
    return *this;
}


int main(){
    Player p1;
    p1 = string("something");
}
