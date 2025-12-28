#include "employee.h"
#include <iomanip>

Employee::Employee()
{

    name = "";
    userID = 0;
    email = "";
    salary = 0;
    position = "";
}

Employee::Employee(int id, const string &name, const string &email, double salary, const string &position)
{
    userID = id;
    this->name = name;
    this->email = email;
    this->salary = salary;
    this->position = position;
}
Employee::~Employee() {};

//---------------------------------
// Getterlar
double Employee::getSalary() const
{
    return salary;
}

string Employee::getPosition() const
{
    return position;
}
//----------------------------------
// Setterlar
void Employee::setSalary(double s)
{
    salary = s;
}
void Employee::setPosition(const string &s)
{
    position = s;
}

void Employee::displayInfo() const
{
    cout << "\n----- Calisan Bilgileri -----" << endl;

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

    cout << "----------------------------" << endl;
}
