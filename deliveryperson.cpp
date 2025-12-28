#include "deliveryperson.h"
#include "order.h"
#include <iostream>
#include <iomanip>

// ---------------------------------
// Constructor'lar
DeliveryPerson::DeliveryPerson() : Employee()
{
    assignedOrders = nullptr;
    orderCount = 0;
}

DeliveryPerson::DeliveryPerson(int id,
                               const string &name,
                               const string &email,
                               double salary,
                               const string &position)
    : Employee(id, name, email, salary, position)
{
    assignedOrders = nullptr;
    orderCount = 0;
}

// ---------------------------------
// Destructor
DeliveryPerson::~DeliveryPerson()
{
    delete[] assignedOrders;
}

// ---------------------------------
// Sipariş atama
void DeliveryPerson::assignOrder(Order *order)
{
    Order **temp = new Order *[orderCount + 1];

    for (int i = 0; i < orderCount; i++)
        temp[i] = assignedOrders[i];

    temp[orderCount] = order;

    delete[] assignedOrders;
    assignedOrders = temp;
    orderCount++;
}

// ---------------------------------
// Atanan siparişleri göster
void DeliveryPerson::showAssignedOrders() const
{
    if (orderCount == 0)
    {
        cout << "Atanmis siparis yok." << endl;
        return;
    }

    cout << "\n===== AKTIF KURYE SIPARISLERI =====" << endl;

    bool found = false; // En az bir aktif siparis var mi kontrolu
    for (int i = 0; i < orderCount; i++)
    {
        // Sadece teslim edilmemis siparisler gosterilir
        if (assignedOrders[i]->getStatus() != DELIVERED)
        {
            assignedOrders[i]->showOrder();
            found = true;
        }
    }

    if (!found)
    {
        cout << "Teslim edilecek aktif siparis yok." << endl;
    }
}

// ---------------------------------
// Calisma fonksiyonu
void DeliveryPerson::work()
{
    cout << "Kurye su anda siparis teslim ediyor." << endl;
}

// ---------------------------------
// Bilgi gösterimi
void DeliveryPerson::displayInfo() const
{
    cout << "\n===== Kurye Bilgileri =====" << endl;

    cout << left
         << setw(15) << "User ID:"
         << userID << endl
         << setw(15) << "Isim:"
         << name << endl
         << setw(15) << "Email:"
         << email << endl
         << setw(15) << "Pozisyon:"
         << position << endl
         << setw(15) << "Maas:"
         << fixed << setprecision(2) << salary << " TL" << endl
         << setw(15) << "Siparis Sayisi:"
         << orderCount << endl;

    cout << "===========================" << endl;
}
