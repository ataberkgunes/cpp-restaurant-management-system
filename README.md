# Restaurant Order and Management System (C++)

This project is a console-based Restaurant Order and Management System developed using the C++ language. The project was prepared as a term project to practically demonstrate the principles of Object-Oriented Programming (OOP).

## Project Goal

The main goal of the application is to model a real-life scenario using the fundamental concepts of OOP (Inheritance, Polymorphism, Encapsulation). The system consists of two main modules: customer and restaurant management.

Users can access the system to:

- List different restaurants
- Browse menus
- Create orders and view order history

Managers can:

- Add new items to the menu
- Add new employees to the system
- List employee information

## Demonstrated OOP Concepts

### Classes
Well-defined classes such as Restaurant, User, Customer, Employee, Manager, MenuItem, Order are present.

### Inheritance
Customer and Employee classes are derived from the User class.  
Manager and DeliveryPerson classes are derived from the Employee class.  
FoodItem and DrinkItem classes are derived from the MenuItem abstract class.

### Polymorphism
Thanks to virtual functions like displayInfo() and work(), the correct method of the derived class is called via the base class pointer.  
The MenuItem pointer array can hold both FoodItem and DrinkItem objects.

### Abstract Classes
Abstract classes like MenuItem and Employee are used to ensure that certain functions (showItem(), work() etc.) are compulsorily implemented by derived classes.

### Encapsulation
Class data members are defined as private or protected, and controlled access to these members is provided only through the public interface (getter/setter methods).

## Note

In line with the requirements of this project, STL (Standard Template Library) collections such as std::vector and std::list were not used to understand the basics of memory management. Instead, dynamic arrays and manual memory management (new[], delete[]) were preferred.

## How to Compile and Run

You need a C++ compiler (e.g., g++) to compile and run the project.

1. **Open your terminal/command prompt and navigate to the project folder** (e.g., after cloning from GitHub):

```bash
cd path/to/your/project-folder
```

2. **Compile all `.cpp` files using the following command:**

```bash
g++ -o restaurant_app main.cpp user.cpp customer.cpp employee.cpp manager.cpp deliveryperson.cpp restaurant.cpp order.cpp menuitem.cpp fooditem.cpp drinkitem.cpp
```

3. **After compilation is complete, run the application:**

```bash
./restaurant_app.exe
```

