#ifndef INSUFFICENTFUNDSEXCEPTION_H
#define INSUFFICENTFUNDSEXCEPTION_H

class InsufficentFundsException : public std::exception
{
public:
    InsufficentFundsException() {}
    virtual const char* what() const noexcept override { return "Insufficent funds"; }
    ~InsufficentFundsException() {}

};

#endif // INSUFFICENTFUNDSEXCEPTION_H
