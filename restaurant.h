#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;
// Forward Declaration Önden Tanımlama
class MenuItem;
class Employee;
class Manager;

class Restaurant
{
private:
    string name;
    string address;

    MenuItem **menuItems; // Menu food+drink
    int menuItemCount;

    Employee **employees;
    int employeeCount;

    Manager *manager;

public:
    // Yapıcılar ve yıkıcı
    Restaurant();
    Restaurant(const string &name, const string &adress);
    ~Restaurant();

    // Menu islemleri
    void addMenuItem(MenuItem *item);
    void showMenu() const;

    // Calısan islemleri
    void addEmployee(Employee *emp);
    void showEmployees() const;

    // Manager işlemleri
    void setManager(Manager *mgr);
    Manager *getManager() const;

    // Getterlar
    string getName() const;
    string getAddress() const;
    int getEmployeeCount() const;
    Employee** getEmployees() const;
};
#endif
