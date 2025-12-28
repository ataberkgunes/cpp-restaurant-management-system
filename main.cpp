#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

#include "restaurant.h"
#include "manager.h"
#include "deliveryperson.h"
#include "customer.h"
#include "order.h"
#include "fooditem.h"
#include "drinkitem.h"
using namespace std;

// Fonksiyon prototipleri
void showMainMenu();
void showManagerMenu();
void handleManagerActions(Restaurant *restaurant);
Customer *selectCustomer(Customer **customers, int customerCount);

int main()
{
    // ---------- 1. RESTORAN VE KURULUMLARI ----------
    Restaurant *restaurant1 = new Restaurant("Lezzet Dunyasi", "Istanbul / Kadikoy");
    Manager *manager1 = new Manager(1, "Dogukan Bingol", "dogukan@lezzet.com", 25000, "Manager");
    restaurant1->setManager(manager1);
    manager1->setRestaurant(restaurant1);
    DeliveryPerson *courier1 = new DeliveryPerson(2, "Kutay Keles", "kutay@lezzet.com", 15000, "Kurye");
    restaurant1->addEmployee(courier1);
    restaurant1->addMenuItem(new FoodItem("1.Pizza", 120, 450));
    restaurant1->addMenuItem(new FoodItem("2.Burger", 95, 350));
    restaurant1->addMenuItem(new DrinkItem("3.Kola", 30, 330));

    // ---------- 2. RESTORAN VE KURULUMLARI ----------
    Restaurant *restaurant2 = new Restaurant("Kebap Cenneti", "Ankara / Kızılay");
    Manager *manager2 = new Manager(10, "Beyza Sude Aydin", "beyza@kebap.com", 28000, "Manager");
    restaurant2->setManager(manager2);
    manager2->setRestaurant(restaurant2);
    DeliveryPerson *courier2 = new DeliveryPerson(11, "Kutay Keles", "fatma@kebap.com", 16000, "Kurye");
    restaurant2->addEmployee(courier2);
    restaurant2->addMenuItem(new FoodItem("1.Adana Kebap", 150, 600));
    restaurant2->addMenuItem(new FoodItem("2.Lahmacun", 70, 300));
    restaurant2->addMenuItem(new DrinkItem("3.Salgam Suyu", 20, 300));

    // ---------- MÜŞTERİLER (DYNAMIC ARRAY) ----------
    int customerCount = 3;
    Customer **customers = new Customer *[customerCount];

    customers[0] = new Customer(100, "Taha Dinc", "taha@gmail.com", "Trabzon / Kalkınma");
    customers[1] = new Customer(101, "Ataberk Günes", "atat@gmail.com", "Trabzon / Besirli");
    customers[2] = new Customer(102, "Onur Karaahmetoglu", "omur@gmail.com", "Trabzon / Besirli");

    int orderIDCounter = 1;

    // Genel program döngüsü
    while (true)
    {
        Restaurant *selectedRestaurant = nullptr;
        DeliveryPerson *selectedCourier = nullptr;

        int restaurantChoice;
        cout << "\n===== RESTORAN SECIMI =====" << endl;
        cout << "1. " << restaurant1->getName() << endl;
        cout << "2. " << restaurant2->getName() << endl;
        cout << "0. Programdan Cik" << endl;
        cout << "Seciminiz: ";
        cin >> restaurantChoice;

        if (restaurantChoice == 1)
        {
            selectedRestaurant = restaurant1;
            selectedCourier = courier1;
        }
        else if (restaurantChoice == 2)
        {
            selectedRestaurant = restaurant2;
            selectedCourier = courier2;
        }
        else if (restaurantChoice == 0)
        {
            cout << "Programdan cikiliyor..." << endl;
            break;
        }
        else
        {
            cout << "Gecersiz secim, lutfen tekrar deneyin." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cout << "\n"
             << selectedRestaurant->getName() << " restoranina hos geldiniz!" << endl;

        Order *lastOrder = nullptr;
        int choice;

        do
        {
            showMainMenu();
            cin >> choice;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Gecersiz giris, lutfen bir sayi girin." << endl;
                choice = -1;
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (choice)
            {
            case 1:
                cout << "\n===== SECILI RESTORAN ====" << endl;
                cout << "Restoran : " << selectedRestaurant->getName() << endl;
                cout << "Adres    : " << selectedRestaurant->getAddress() << endl;
                break;
            case 2:
                selectedRestaurant->showMenu();
                break;
            case 3:
            {
                Customer *orderingCustomer = selectCustomer(customers, customerCount);
                if (orderingCustomer == nullptr)
                {
                    cout << "Musteri secilmedi, ana menuye donuluyor." << endl;
                    break;
                }

                Order *newOrder = new Order(orderIDCounter++, orderingCustomer);
                int itemChoice;
                do
                {
                    selectedRestaurant->showMenu();
                    cout << "Lutfen menudeki urunun numarasini girin (0 = Bitir): ";
                    cin >> itemChoice;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        itemChoice = -1;
                        continue;
                    }

                    if (itemChoice > 0 && itemChoice <= 3)
                    {
                        if (selectedRestaurant == restaurant1)
                        {
                            if (itemChoice == 1)
                                newOrder->addItem(new FoodItem("1.Pizza", 120, 450));
                            else if (itemChoice == 2)
                                newOrder->addItem(new FoodItem("2.Burger", 95, 350));
                            else if (itemChoice == 3)
                                newOrder->addItem(new DrinkItem("3.Kola", 30, 330));
                        }
                        else if (selectedRestaurant == restaurant2)
                        {
                            if (itemChoice == 1)
                                newOrder->addItem(new FoodItem("1.Adana Kebap", 150, 600));
                            else if (itemChoice == 2)
                                newOrder->addItem(new FoodItem("2.Lahmacun", 70, 300));
                            else if (itemChoice == 3)
                                newOrder->addItem(new DrinkItem("3.Salgam Suyu", 20, 300));
                        }
                    }
                } while (itemChoice != 0);

                if (newOrder->getItemCount() > 0)
                {
                    orderingCustomer->addOrder(newOrder);
                    if (selectedCourier)
                        selectedCourier->assignOrder(newOrder);
                    lastOrder = newOrder;
                    cout << "Siparis olusturuldu!" << endl;
                }
                else
                {
                    cout << "Siparise urun eklenmedi, islem iptal edildi." << endl;
                    delete newOrder;
                }
                break;
            }
            case 4:
            {
                Customer *viewingCustomer = selectCustomer(customers, customerCount);
                if (viewingCustomer != nullptr)
                    viewingCustomer->showOrders();
                else
                    cout << "Musteri secilmedi, ana menuye donuluyor." << endl;
                break;
            }
            case 5:
                if (selectedCourier)
                    selectedCourier->showAssignedOrders();
                else
                    cout << "Bu restoranda kurye bulunamadi." << endl;
                break;
            case 6:
                if (lastOrder != nullptr)
                {
                    cout << "1. Hazirlaniyor\n2. Yolda\n3. Teslim Edildi\nSecim: ";
                    int s;
                    cin >> s;
                    if (s == 1)
                        lastOrder->setStatus(PREPARING);
                    else if (s == 2)
                        lastOrder->setStatus(ON_THE_WAY);
                    else if (s == 3)
                        lastOrder->setStatus(DELIVERED);
                    cout << "Siparis durumu guncellendi." << endl;
                }
                else
                {
                    cout << "Henuz siparis yok." << endl;
                }
                break;
            case 7:
                handleManagerActions(selectedRestaurant);
                break;
            case 8:
                cout << "Restoran secim ekranina donuluyor..." << endl;
                break;
            case 0:
                cout << "Programdan cikiliyor..." << endl;
                choice = 0;
                break;
            default:
                cout << "Gecersiz secim!" << endl;
            }
        } while (choice != 8 && choice != 0);

        if (choice == 0)
            break;
    }

    // Bellek temizliği
    delete restaurant1;
    delete restaurant2;
    delete manager1;
    delete manager2;
    delete courier1;
    delete courier2;

    for (int i = 0; i < customerCount; ++i)
        delete customers[i];
    delete[] customers;

    return 0;
}

// ------------------ FONKSIYONLAR ------------------

Customer *selectCustomer(Customer **customers, int customerCount)
{
    cout << "\n--- Musteri Sec ---" << endl;
    for (int i = 0; i < customerCount; ++i)
        cout << i + 1 << ". " << customers[i]->getName() << endl;

    cout << "0. Geri" << endl;
    cout << "Seciminiz: ";

    int choice;
    cin >> choice;
    if (cin.fail() || choice < 0 || choice > customerCount)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return nullptr;
    }
    if (choice == 0)
        return nullptr;
    return customers[choice - 1];
}

void showMainMenu()
{
    cout << "\n========== ANA MENU ==========" << endl;
    cout << "1. Restoran Bilgilerini Goster" << endl;
    cout << "2. Restoran Menusunu Goruntule" << endl;
    cout << "3. Yeni Siparis Olustur" << endl;
    cout << "4. Musteri Siparis Gecmisini Goruntule" << endl;
    cout << "5. Aktif Kurye Siparislerini Goruntule" << endl;
    cout << "6. Son Siparisin Durumunu Degistir" << endl;
    cout << "7. Yonetici Islemleri" << endl;
    cout << "8. Baska Bir Restoran Sec" << endl;
    cout << "0. Programdan Cik" << endl;
    cout << "Seciminiz: ";
}

void showManagerMenu()
{
    cout << "\n===== YONETICI ISLEMLERI ====" << endl;
    cout << "1. Menuye Yeni Urun Ekle" << endl;
    cout << "2. Yeni Calisan Ekle (Kurye)" << endl;
    cout << "3. Calisanlari Listele" << endl;
    cout << "0. Ana Menuye Don" << endl;
    cout << "Seciminiz: ";
}

void handleManagerActions(Restaurant *restaurant)
{
    int managerChoice;
    do
    {
        showManagerMenu();
        cin >> managerChoice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            managerChoice = -1;
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (managerChoice)
        {
        case 1:
        {
            cout << "Urun tipi (1: Yiyecek, 2: Icecek): ";
            int type;
            cin >> type;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Urun adi: ";
            string name;
            getline(cin, name);
            cout << "Fiyat: ";
            double price;
            cin >> price;
            if (type == 1)
            {
                cout << "Porsiyon (gr): ";
                int portion;
                cin >> portion;
                restaurant->addMenuItem(new FoodItem(name, price, portion));
            }
            else if (type == 2)
            {
                cout << "Hacim (ml): ";
                int volume;
                cin >> volume;
                restaurant->addMenuItem(new DrinkItem(name, price, volume));
            }
            cout << "Urun basariyla menuye eklendi!" << endl;
            break;
        }
        case 2:
        {
            cout << "Calisan adi: ";
            string name;
            getline(cin, name);
            cout << "Email: ";
            string email;
            getline(cin, email);
            cout << "Maas: ";
            double salary;
            cin >> salary;
            int newId = 30 + restaurant->getEmployeeCount();
            restaurant->addEmployee(new DeliveryPerson(newId, name, email, salary, "Kurye"));
            cout << "Calisan basariyla eklendi!" << endl;
            break;
        }
        case 3:
            restaurant->showEmployees();
            break;
        case 0:
            cout << "Ana menuye donuluyor..." << endl;
            break;
        default:
            cout << "Gecersiz secim!" << endl;
        }
    } while (managerChoice != 0);
}
