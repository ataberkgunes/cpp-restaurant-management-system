#include "manager.h"
#include "restaurant.h"
#include <iostream>
#include <iomanip>

//-----------------------
// Yapıcılar ve Yıkıcı
Manager::Manager() : Employee()
{
    restaurant = nullptr;
}

Manager::Manager(int id, const string &name, const string &email, double salary, const string &position)
    : Employee(id, name, email, salary, position)
{
    restaurant = nullptr;
}

Manager::~Manager() {}

void Manager::setRestaurant(Restaurant *res)
{
    restaurant = res;
}

Restaurant *Manager::getRestaurant() const
{
    return restaurant;
}

// Manager işi
void Manager::work()
{
    cout << "Manager mesgul yönetimle ugrasıyor." << endl;
}

// Manager DisplayInfo
void Manager::displayInfo() const
{
    cout << "\n===== Yonetici Bilgileri =====" << endl;

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
         << fixed << setprecision(2) << salary << " TL" << endl;

    if (restaurant != nullptr)
    {
        cout << setw(15) << "Restoran:"
             << restaurant->getName() << endl;
    }
    else
    {
        cout << setw(15) << "Restoran:"
             << "Atanmadi" << endl;
    }

    cout << "=============================" << endl;
}
