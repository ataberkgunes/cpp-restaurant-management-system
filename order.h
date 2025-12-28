#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
// #include "menuItem.h" // MenuItem soyut sınıfı
using namespace std;

// Sipariş durumları kafamız karışmasın dıye enumda tuttum
enum OrderStatus
{
    PREPARING,
    ON_THE_WAY,
    DELIVERED
};
class MenuItem; // Burada da forward declaration var
class Customer;

class Order
{
private:
    int orderID;
    MenuItem **items; // Siparişteki ürünler (dinamik dizi)
    int itemCount;
    OrderStatus status;
    double totalPrice;
    Customer *customer; // Siparişi veren müşteri

    void calculateTotalPrice(); // Toplam fiyatı hesaplar

public:
    // Constructor ve deconstructor
    Order(int id, Customer *owner);
    ~Order();

    // Sipariş işlemleri
    void addItem(MenuItem *item); // Ürün ekle
    void showOrder() const;       // Sipariş detaylarını göster

    // Getter'lar
    int getOrderID() const;
    int getItemCount() const;
    double getTotalPrice() const;
    OrderStatus getStatus() const;
    Customer *getCustomer() const;

    // Setter
    void setStatus(OrderStatus newStatus);
};

#endif
