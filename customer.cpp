#include "customer.h"
#include "order.h"
#include <iostream>
#include <iomanip>

//----------------------------------------
// Kurucu ve Yıkıcılar
Customer::Customer()
{
    name = "";
    userID = 0;
    email = "";
    address = "";
    orders = nullptr;
    orderCount = 0;
}

Customer::Customer(int userID, const string &name, const string &email, const string &address)
{
    this->userID = userID;
    this->name = name;
    this->email = email;
    this->address = address;
    orders = nullptr;
    orderCount = 0;
}

Customer::~Customer()
{
    if (orders != nullptr)
    {
        delete[] orders;
    }
}

//--------------------------------------
// Getter fonksiyonu
string Customer::getAddress() const
{
    return address;
}
//----------------------------------------
// Setter fonksiyonu
void Customer::setAddress(const string &addr)
{
    address = addr;
}
void Customer::addOrder(Order *newOrder)
{
    // Yeni dizi oluştur
    Order **temp = new Order *[orderCount + 1];

    // Eski siparişleri kopyala
    for (int i = 0; i < orderCount; i++)
    {
        temp[i] = orders[i];
    }

    // Yeni siparişi ekle
    temp[orderCount] = newOrder;

    // Eski diziyi sil
    delete[] orders;

    // Yeni diziyi ata
    orders = temp;
    orderCount++;
}
void Customer::showOrders() const
{
    if (orderCount == 0)
    {
        cout << "Bu müşteriye ait sipariş yok." << endl;
        return;
    }

    cout << "===== Müşterinin Siparis Gecmisi =====" << endl;
    for (int i = 0; i < orderCount; i++)
    {
        orders[i]->showOrder();
    }
}

//------------------------------------------
// Display fonksiyonu
void Customer::displayInfo() const
{
    cout << "\n----- Musteri Bilgileri -----" << endl;

    cout << left
         << setw(15) << "User ID:"
         << userID << endl
         << setw(15) << "Isim:"
         << name << endl
         << setw(15) << "Email:"
         << email << endl
         << setw(15) << "Adres:"
         << address << endl;

    cout << "----------------------------" << endl;
}
