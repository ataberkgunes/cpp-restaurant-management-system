#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

using namespace std;

class User
{
protected:
    string name;
    int userID;
    string email;

public:
    // Constractur ve deconstractur prototipleri
    User();
    User(int id, const string &name, const string &email);
    virtual ~User(); // Base class destructor'ı mutlaka virtual olmalı

    // Getter prototipleri
    int getUserID() const;
    string getName() const;
    string getEmail() const;

    // Setter prototipleri

    void setUserID(int id);
    void setName(const string &name);
    void setEmail(const string &email);

    // Rollerin belirlenmesi için
    virtual string getRole() const;
    // Sanal fonksiyon (Polymorphism için)
    virtual void displayInfo() const;
};

#endif