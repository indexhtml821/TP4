#include "product.h"
#include <string.h>
#include "exceptionValueOverflowMember.h"

Product::~Product()
{
}
Product::Product(int productId,
                 int amount,
                 string name)
{

    if (sizeof(this->prodName) < name.length())
    {
        throw ExceptionValueOverflowMember();
        return;
    }

    this->productId = productId;
    this->amount = amount;
    char prodName[20];
    strcpy(this->prodName, name.c_str());
}

Product::Product()
{
    this->productId = 0;
    this->amount = 0;
    strcpy(this->prodName, "");
}

int Product::getId()
{
    return this->productId;
}
void Product::setName(string name)
{
    if (sizeof(this->prodName) < name.length())
    {
        throw ExceptionValueOverflowMember();
        return;
    }
    strcpy(this->prodName, name.c_str());
}

string Product::getName()
{
    return this->prodName;
}

void Product::setAmount(int amount)
{

    this->amount = amount;
}

ostream &operator<<(ostream &o, const Product *product)
{
    o  << product->productId << " -  " << product->prodName << " - " << product->amount;
    return o;
}
