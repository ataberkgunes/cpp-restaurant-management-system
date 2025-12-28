#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "user.h"

using namespace std;

class Order; // Forward declaration yani önden tanımlama

class Customer : public User
{
private:
    string address;
    Order **orders; // Müşterinin siparişleri
    int orderCount;

public:
    Customer();
    Customer(int userID, const string &name, const string &email, const string &address);
    ~Customer();

    // Getter ve setter
    string getAddress() const;
    void setAddress(const string &addr);

    // Sipariş İşlemleri
    void addOrder(Order *newOrder); // Sipariş ekleme
    void showOrders() const;        // Siparişleri göster

    // --- Override ---
    void displayInfo() const override;
};

#endif
