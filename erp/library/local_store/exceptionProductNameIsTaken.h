#ifndef EXCEPTIONPRODUCTNAMEISTAKEN_H
#define EXCEPTIONPRODUCTNAMEISTAKEN_H

#include <exception>

class ExceptionProductNameIsTaken : public std::exception
{
public:
    ExceptionProductNameIsTaken() noexcept = default;
    ~ExceptionProductNameIsTaken() = default;

    virtual const char *what() const noexcept
    {
        return "Product name has already been taken, try changing already existing product amount";
    }
};

#endif
