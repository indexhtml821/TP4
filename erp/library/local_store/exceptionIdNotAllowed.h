#ifndef EXCEPTIONIDNOTALLOWED_H
#define EXCEPTIONIDNOTALLOWED_H

#include <exception>

class ExceptionIdNotAllowed : public std::exception
{
public:
    ExceptionIdNotAllowed() noexcept = default;
    ~ExceptionIdNotAllowed() = default;

    virtual const char *what() const noexcept
    {
        return "Product id doesnt exists/not allowed";
    }
};

#endif
