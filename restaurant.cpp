#include "restaurant.h"
#include "menuitem.h"
#include "employee.h"
#include "manager.h"

// ---------------------------------
// Constructor'lar
Restaurant::Restaurant()
{
    name = "";
    address = "";
    menuItems = nullptr;
    menuItemCount = 0;
    employees = nullptr;
    employeeCount = 0;
    manager = nullptr;
}

Restaurant::Restaurant(const string &name, const string &address)
{
    this->name = name;
    this->address = address;
    menuItems = nullptr;
    menuItemCount = 0;
    employees = nullptr;
    employeeCount = 0;
    manager = nullptr;
}

// ---------------------------------
// Destructor
Restaurant::~Restaurant()
{
    delete[] menuItems;
    delete[] employees;
    // manager silinmez (dışarıdan atanır)
}

// ---------------------------------
// Menüye ürün ekleme
void Restaurant::addMenuItem(MenuItem *item)
{
    MenuItem **temp = new MenuItem *[menuItemCount + 1];

    for (int i = 0; i < menuItemCount; i++)
        temp[i] = menuItems[i];

    temp[menuItemCount] = item;

    delete[] menuItems;
    menuItems = temp;
    menuItemCount++;
}

// ---------------------------------
// Menü gösterme
void Restaurant::showMenu() const
{
    if (menuItemCount == 0)
    {
        cout << "Menu bos." << endl;
        return;
    }

    cout << "\n===== " << name << " MENUSU =====" << endl;

    cout << left
         << setw(15) << "Tur"
         << setw(20) << "Urun Adi"
         << setw(10) << "Fiyat"
         << setw(10) << ""
         << setw(15) << "Ozellik"
         << endl;

    cout << string(70, '-') << endl;

    for (int i = 0; i < menuItemCount; i++)
    {
        menuItems[i]->showItem(); // POLYMORPHISM
    }

    cout << string(70, '-') << endl;
}

// --------------
// Çalışan ekleme
void Restaurant::addEmployee(Employee *emp)
{
    Employee **temp = new Employee *[employeeCount + 1];

    for (int i = 0; i < employeeCount; i++)
        temp[i] = employees[i];

    temp[employeeCount] = emp;

    delete[] employees;
    employees = temp;
    employeeCount++;
}

// ---------------------
// Çalışanları listeleme
void Restaurant::showEmployees() const
{
    if (employeeCount == 0)
    {
        cout << "Calisan yok." << endl;
        return;
    }

    cout << "\n===== CALISAN LISTESI =====" << endl;
    for (int i = 0; i < employeeCount; i++)
    {
        employees[i]->displayInfo(); // Polymorphism
    }
}

// ---------------------------------
// Manager işlemleri
void Restaurant::setManager(Manager *mgr)
{
    manager = mgr;
}

Manager *Restaurant::getManager() const
{
    return manager;
}

// ---------------------------------
// Getterlar
string Restaurant::getName() const
{
    return name;
}

string Restaurant::getAddress() const
{
    return address;
}

int Restaurant::getEmployeeCount() const
{
    return employeeCount;
}

Employee** Restaurant::getEmployees() const
{
    return employees;
}
