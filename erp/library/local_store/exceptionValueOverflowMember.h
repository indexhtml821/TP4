#ifndef EXCEPTIONVALUEOVERFLOWMEMBER_H
#define EXCEPTIONVALUEOVERFLOWMEMBER_H

#include <exception>

class ExceptionValueOverflowMember : public std::exception
{
public:
    ExceptionValueOverflowMember() noexcept = default;
    ~ExceptionValueOverflowMember() = default;

    virtual const char *what() const noexcept
    {
        return "Value passed over flows member capacity";
    }
};

#endif
