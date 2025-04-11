/* Name: Fahad Qureshi
    Roll No: 24K-0824 */
#include "iostream"
using namespace std;

class Car {
    string model;
    double price;
    public:
    Car(string model, double price) : model(model), price(price) {}
    Car() {}

    friend class InventoryManager;
    friend void operator==(Car &c1, Car &c2);
};

class InventoryManager {
    Car *Car1;
    public:
    InventoryManager(Car &car)  { 
        Car1 = new Car(car);
    }
    void setModel(string model) {Car1->model= model;}
    void setPrice (double price) {Car1->price = price;}

    void displayDetails() { 
        cout << "Model: " << Car1->model << endl;
        cout << "Price: " << Car1->price << endl;
    }

    ~InventoryManager() {
        delete Car1;
    }
};

void operator==(Car &c1, Car &c2) {
    if (c1.price > c2.price) {cout << "The Car " << c1.model << " is more expensive." << endl;}
    else if (c1.price < c2.price) {cout << "The Car " << c2.model << " is more expensive." << endl;}
    else if (c1.price = c2.price) {cout << "The Cars are same in price." << endl;}
}

int main() {
    Car Car1("Mazda", 78000.99);
    Car Car2("Civic", 77800.21);

    InventoryManager Manager(Car1);
    Manager.setPrice(78000.98);

    Car1 == Car2;

    return 0;    
}

