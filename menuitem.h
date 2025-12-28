#ifndef MENUITEM_H
#define MENUITEM_H

#include <iostream>
#include <string>
using namespace std;

class MenuItem
{

protected:
    string name;
    double price;

public:
    // Constructor ve deconstructor
    MenuItem();
    MenuItem(const string &name, double price);
    virtual ~MenuItem();

    // Getterlar
    string getName() const;
    double getPrice() const;

    // Setterlar
    void setName(const string &name);
    void setPrice(const double price);

    // Virtual Fonksiyonlar
    virtual void showItem() const = 0;
    virtual double calculateDiscount() const = 0;
};
#endif