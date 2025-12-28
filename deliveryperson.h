#ifndef DELIVERYPERSON_H
#define DELIVERYPERSON_H

#include "employee.h"

using namespace std;

class Order; // forward declaration

class DeliveryPerson : public Employee
{
private:
    Order **assignedOrders; // Atanan siparişler
    int orderCount;

public:
    // Constructor & Destructor
    DeliveryPerson();
    DeliveryPerson(int id,
                   const string &name,
                   const string &email,
                   double salary,
                   const string &position);

    ~DeliveryPerson();

    // Sipariş işlemleri
    void assignOrder(Order *order);
    void showAssignedOrders() const;

    // Employee abstract fonksiyon
    void work() override;

    // Bilgi gösterimi
    void displayInfo() const override;
};

#endif
