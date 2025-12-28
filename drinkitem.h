#ifndef DRINKITEM_H
#define DRINKITEM_H

#include "menuitem.h"

class DrinkItem : public MenuItem
{

private:
    int volume;

public:
    // Yapıcılar ve Yıkıcı
    DrinkItem();
    DrinkItem(const string &name, double price, int volume);
    ~DrinkItem();

    // Getter ve setter
    int getVolume() const;
    void setVolume(int volume);

    // Polymorphism
    void showItem() const override;
    double calculateDiscount() const override;
};
#endif