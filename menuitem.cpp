#include "menuitem.h"

//------------------------
// Constructorlar

MenuItem::MenuItem()
{
    name = "";
    price = 0.0;
}
MenuItem::MenuItem(const string &name, double price)
{
    this->name = name;
    this->price = price;
}

//-------------------
// Deconstructor

MenuItem::~MenuItem() {};

//----------------
// Getterlar
string MenuItem::getName() const
{
    return name;
}

double MenuItem::getPrice() const
{
    return price;
}

//----------------------
// Setterlar
void MenuItem::setName(const string &name)
{
    this->name = name;
}

void MenuItem::setPrice(const double price)
{
    this->price = price;
}