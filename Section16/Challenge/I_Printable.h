#ifndef I_PRINTABLE_H
#define I_PRINTABLE_H
#include <iostream>


class I_Printable
{
public:
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
    virtual void print(std::ostream &os) const = 0;
    virtual ~I_Printable() {};

};

#endif // I_PRINTABLE_H
