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
    Car() {
        brand = "Unknown";
        model = "Generic";
        price = 0.0;
        availibility_status = 1;
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
        availibility_status = 0;
        cout << "You have rented the car!" << endl;
    }

    void availibility_statuss() {
        bool a;
        cout << "Availibility status(1 or 0): ";
        cin >> a;
        availibility_status = a;
        cout << "Updated" << endl;
    }
};


int main () {
    Car Mazda6;
    Mazda6.availibility_statuss();
    Mazda6.check_availability();
    Mazda6.rental_request();
    Mazda6.update();
    return 0;
} 
