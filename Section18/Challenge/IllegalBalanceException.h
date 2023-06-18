#ifndef __ILLEGAL_BALANCE_EXCEPTION_H__
#define __ILLEGAL_BALANCE_EXCEPTION_H__

class IllegalBalanceException : public std::exception
{
public:
    IllegalBalanceException() {}
    virtual const char* what() const noexcept override { return "Could not create the object, negative balance"; }
    ~IllegalBalanceException() {}
};

#endif // __ILLEGAL_BALANCE_EXCEPTION_H__
