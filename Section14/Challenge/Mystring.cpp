#include <iostream>
#include <cstring>
#include "Mystring.hpp"

 // No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
//     std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring(Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
        std::cout << "Move constructor used" << std::endl;
}

 // Destructor
Mystring::~Mystring() {
    delete [] str;
}

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
//    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=( Mystring &&rhs) {
 //   std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

 // getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

bool operator==(const Mystring &lhs, const Mystring &rhs){
    return strcmp(lhs.str, rhs.str) == 0;
}

bool operator!=(const Mystring &lhs, const Mystring &rhs) {
    return strcmp(lhs.str, rhs.str) != 0;
}


Mystring operator-(const Mystring &m) {
    Mystring result(m);
    
    for (int i = 0; i < result.get_length(); ++i) {
        result.str[i] = tolower(result.str[i]);
    }
    return result;
}

bool operator<(const Mystring &lhs, const Mystring &rhs) {
    return strcmp(lhs.str, rhs.str) < 0;
}

bool operator>(const Mystring &lhs, const Mystring &rhs) {
    return strcmp(lhs.str, rhs.str) > 0;
}

Mystring operator+(const Mystring &lhs, const Mystring &rhs) {
    Mystring result;
    result.str = new char[strlen(lhs.str) + strlen(rhs.str) + 1];    
    strcat(result.str, lhs.str);
    strcat(result.str, rhs.str);

    return result;
}

void operator+=(Mystring &lhs, const Mystring &rhs) {
    lhs = lhs + rhs;
}

Mystring operator*(const Mystring &m, const int &times) {
    Mystring result;
    result.str = new char[strlen(m.str) * times + 1];
    for (int i = 0; i < times; i++)
        strcat(result.str, m.str);
    return result;
}


void operator*=(Mystring &lhs, const int &rhs) {
    lhs = lhs * rhs;
}

Mystring &operator++(Mystring &m) {
    for (int i = 0; i < m.get_length(); ++i) {
        m.str[i] = toupper(m.str[i]);
    }
    return m;
}

Mystring operator++(Mystring &m, int) {
    Mystring temp(m);
    ++m;
    return temp;
}

