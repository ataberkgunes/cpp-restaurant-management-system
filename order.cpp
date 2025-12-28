#include "order.h"
#include "menuitem.h"
#include "customer.h" // Customer sınıfının tam tanımı için dahil edildi
#include <iostream>
#include <iomanip>

// Constructor
Order::Order(int id, Customer *owner)
{
    orderID = id;
    items = nullptr;
    itemCount = 0;
    totalPrice = 0.0;
    status = PREPARING;
    customer = owner; // Siparişin sahibini ata
}

// Destructor
Order::~Order()
{
    if (items != nullptr)
    {
        // Bu siparişte oluşturulan MenuItem nesneleri de silinmeli
        for (int i = 0; i < itemCount; ++i) {
            delete items[i];
        }
        delete[] items;
    }
}

// Siparişe ürün ekleme
void Order::addItem(MenuItem *item)
{
    // Yeni dizi oluştur
    MenuItem **temp = new MenuItem *[itemCount + 1];

    // Eski elemanları kopyala
    for (int i = 0; i < itemCount; i++)
    {
        temp[i] = items[i];
    }

    // Yeni ürünü ekle
    temp[itemCount] = item;

    // Eski diziyi sil
    delete[] items;

    // Yeni diziyi ata
    items = temp;
    itemCount++;

    // Toplam fiyatı güncelle
    calculateTotalPrice();
}

// -------------------------------
// Toplam fiyat hesaplama
void Order::calculateTotalPrice()
{
    totalPrice = 0.0;
    for (int i = 0; i < itemCount; i++)
    {
        totalPrice += items[i]->getPrice();
    }
}

// Sipariş detaylarını göster
void Order::showOrder() const
{
    cout << "\n===== Siparis Detaylari =====" << endl;
    cout << "Siparis ID : " << orderID << endl;

    // Müşteri bilgileri eklendi
    if (customer != nullptr) {
        cout << "Musteri    : " << customer->getName() << endl;
        cout << "Adres      : " << customer->getAddress() << endl;
    }

    cout << "Durum      : ";
    if (status == PREPARING)
        cout << "Hazirlaniyor";
    else if (status == ON_THE_WAY)
        cout << "Yolda";
    else
        cout << "Teslim Edildi";
    cout << endl
         << endl;

    // TABLO BAŞLIĞI
    cout << left
         << setw(15) << "Tur"
         << setw(20) << "Urun Adi"
         << setw(10) << "Fiyat"
         << setw(10) << ""
         << setw(15) << "Ozellik"
         << endl;

    cout << string(70, '-') << endl;

    for (int i = 0; i < itemCount; i++)
    {
        items[i]->showItem(); // POLYMORPHISM
    }

    cout << string(70, '-') << endl;
    cout << right << setw(50) << "Toplam Tutar: "
         << fixed << setprecision(2) << totalPrice << " TL" << endl;
}

// Getter'lar
int Order::getOrderID() const
{
    return orderID;
}

int Order::getItemCount() const
{
    return itemCount;
}

double Order::getTotalPrice() const
{
    return totalPrice;
}

OrderStatus Order::getStatus() const
{
    return status;
}

Customer* Order::getCustomer() const
{
    return customer;
}


// Setter
void Order::setStatus(OrderStatus newStatus)
{
    status = newStatus;
}