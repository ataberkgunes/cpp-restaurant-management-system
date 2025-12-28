#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "user.h"
// #include "order.h"
using namespace std;

class Employee : public User
{
protected:
    double salary;
    string position;

public:
    // Constractur ve deconstractur prototipleri
    Employee();
    Employee(int id, const string &name, const string &email, double salary, const string &position);
    virtual ~Employee();

    // Getter ve setterlar
    double getSalary() const;
    void setSalary(double s);

    string getPosition() const;
    void setPosition(const string &s);
    // burda kullandıgımız workun amacı her çalışana ayrı bir görev vermek.
    virtual void work() = 0;

    void displayInfo() const override;
};

#endif