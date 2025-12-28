#ifndef FOODITEM_H
#define FOODITEM_H

#include "menuitem.h"

class FoodItem : public MenuItem
{

private:
    int portionSize; // gram cinsinden porsiyonlar
public:
    // Yapıcı ve Yıkıcılar
    FoodItem();
    FoodItem(const string &name, double price, int portionSize);
    ~FoodItem();
    // Getter ve Setterlar
    int getPortionSize() const;
    void setPortionSize(int size);

    // Polymorphism
    void showItem() const override;
    double calculateDiscount() const override;
};
#endif