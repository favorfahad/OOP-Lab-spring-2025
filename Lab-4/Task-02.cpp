/* Name: Fahad Qureshi
  Roll No: 24K-0824
*/
#include<iostream>
#include<string>
using namespace std;

class Car {
    private:
    string brand;
    string model;
    float price;
    bool availibility_status;

    public:
    Car(string b, string m, float p, bool a) {
        brand = b;
        model = m;
        price = p;
        availibility_status = a;
    }

    void update() {
        string b,  m;
        float p;
        bool a;
        cout << "Enter the brand name: ";
        getline(cin, b);
        cout << "Enter the model name: ";
        getline(cin, m);
        cout << "Enter the price: ";
        cin >> p;
        cout << "Availibility status(1 or 0): ";
        cin >> a;
        brand = b;
        model = m;
        price = p;
        availibility_status = a;
    }

    void check_availability() {
        if (availibility_status == 1) {
            cout << "The car is available." << endl;
        } else if (availibility_status == 0) {
            cout << "The car is not available." << endl;
        }
    }

    void rental_request() {
        if (availibility_status == 1) {
        availibility_status = 0;
        cout << "You have rented the car!" << endl;
        }
    }

    void availibility_statuss() {
        bool a;
        cout << "Availibility status(1 or 0): ";
        cin >> a;
        availibility_status = a;
        cout << "Updated" << endl;
    }

    void applydiscount() {
        int days;
        cout << "Enter for how many days the car has been rented: ";
        cin >> days;
        if (days > 10) {
            price *= 0.95;
        } else if (days > 5) {
            price *= 0.90;
        }
    }
};

int main () {

    Car Mazda6("Unknown", "Generic", 0.0, 1);
    Mazda6.availibility_statuss();
    Mazda6.check_availability();
    Mazda6.rental_request();
    Mazda6.update();
    Mazda6.applydiscount();

    return 0;
} 
