#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include "employee.h"

using namespace std;

class Restaurant;

class Manager : public Employee
{
private:
    Restaurant *restaurant;

public:
    // Yapıcılar ve yıkıcı
    Manager();
    Manager(int id, const string &name, const string &email, double salary, const string &position);
    ~Manager();

    // Restaurant bağlantısı
    void setRestaurant(Restaurant *res);
    Restaurant *getRestaurant() const;

    // Employeeden gelen abstract fonksiyon
    void work() override;

    // Bilgilerini gösteren fonk
    void displayInfo() const override;
};
#endif