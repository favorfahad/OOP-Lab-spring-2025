// Name: Fahad Qureshi
// Roll No: 24K-0824

#include <iostream>
using namespace std;

class MenuItem {
    protected:
    string dishName;
    double price;
    public:
    MenuItem(string name, double p) : dishName(name), price(p) {}
    virtual void showDetails() = 0;
    virtual void prepare() = 0;
};

class Appetizer : public MenuItem {
    public:
    Appetizer(string name, double p) : MenuItem(name, p) {}
    void showDetails() override {
        cout << "Appetizer: " << dishName << " - Rs " << price << endl;
    }
    void prepare() override {
        cout << "Preparing: Chill and serve\n";
    }
};

class MainCourse : public MenuItem {
    public:
    MainCourse(string name, double p) : MenuItem(name, p) {}
    void showDetails() override {
        cout << "Main Course: " << dishName << " - Rs " << price << endl;
    }
    void prepare() override {
        cout << "Cooking: Grill and plate\n";
    }
};

int main() {
    MenuItem* menu[] = {
        new Appetizer("Chicken Wings", 1200),
        new MainCourse("Beef Steak", 2500)
    };

    for(MenuItem* item : menu) {
        item->showDetails();
        item->prepare();
        cout << endl;
        delete item;
    }
    return 0;
}
