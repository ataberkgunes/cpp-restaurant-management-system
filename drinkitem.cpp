#include "drinkitem.h"
#include <iomanip>

DrinkItem::DrinkItem() : MenuItem()
{
    volume = 0;
}
DrinkItem::DrinkItem(const string &name, double price, int volume) : MenuItem(name, price)
{
    this->volume = volume;
}
DrinkItem::~DrinkItem() {};

int DrinkItem::getVolume() const
{
    return volume;
}
void DrinkItem::setVolume(int volume)
{
    this->volume = volume;
}
void DrinkItem::showItem() const
{
    cout << left
         << setw(15) << "Icecek"
         << setw(20) << name
         << setw(10) << fixed << setprecision(2) << price
         << setw(10) << "TL"
         << setw(15) << (to_string(volume) + " ml")
         << endl;
}
double DrinkItem::calculateDiscount() const
{
    return price * 0.05;
}
