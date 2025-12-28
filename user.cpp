#include "user.h"
#include <iomanip>
//------------------------------------------
// Kurucu ve yıkıcılar
User::User()
{

    name = "Dogukan";
    userID = 434394;
    email = "m.dogukanbingol55@gmail.com";
};

User::User(int id, const string &name, const string &email)
{
    this->userID = id;
    this->name = name;
    this->email = email;
}

User::~User() {};
//------------------------------------------
// Setter fonksiyonlar
void User::setUserID(int id)
{
    this->userID = id;
};
void User::setEmail(const string &email)
{
    this->email = email;
};
void User::setName(const string &name)
{
    this->name = name;
};
//------------------------------------------
// Getter fonksiyonlar

int User::getUserID() const
{
    return userID;
}
string User::getEmail() const
{
    return email;
}
string User::getName() const
{
    return name;
}

//------------------------------------------
// Display fonksiyonu
void User::displayInfo() const
{
    cout << left
         << setw(15) << "User ID:"
         << userID << endl
         << setw(15) << "Isim:"
         << name << endl
         << setw(15) << "Email:"
         << email << endl;
}

//------------------------------------------
// Rol belirlemek için fonksiyon diğer sınıflarda roller olucak diye düşündük
string User::getRole() const
{
    return "User";
};