#include "fooditem.h"
#include <iomanip>

FoodItem::FoodItem() : MenuItem()
{
    portionSize = 0;
}
FoodItem::FoodItem(const string &name, double price, int portionSize) : MenuItem(name, price)
{
    this->portionSize = portionSize;
}
FoodItem::~FoodItem() {};

int FoodItem::getPortionSize() const
{
    return portionSize;
}

void FoodItem::setPortionSize(int size)
{
    portionSize = size;
}

void FoodItem::showItem() const
{
    cout << left
         << setw(15) << "Yiyecek"
         << setw(20) << name
         << setw(10) << fixed << setprecision(2) << price
         << setw(10) << "TL"
         << setw(15) << (to_string(portionSize) + " gr")
         << endl;
}
double FoodItem::calculateDiscount() const
{
    return price * 0.10;
}