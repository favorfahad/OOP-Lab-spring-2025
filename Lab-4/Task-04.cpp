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
    int days;
    float revenue;

    public:
    Car(string b, string m, float p) {
        brand = b;
        model = m;
        price = p;
        availibility_status = 1;
        revenue = 0.0;
        days = 0;
    }

    Car(const Car &copycar) {
        brand = copycar.brand;
        model = copycar.model;
        price = copycar.price;
        availibility_status = copycar.availibility_status;
        revenue = 0.0;
        days = 0;
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

    void Update_revenue() {
       if (!availibility_status) {
            cout << "Car is already rented!" << endl;
            return;
        }
        cout << "Enter the number of days, this car was rented for: ";
        cin >> days;

        int profit = price * days;
        this->revenue += profit;
        this->availibility_status = 0;

        cout << "Car rented for " << days << " days. Revenue updated to $" << this->revenue << endl;
    } //Updated for task-4

    void Availibility_status() {
        bool a;
        cout << "Enter Availibility status(1 or 0) for " << brand << " : ";
        cin >> a;
        availibility_status = a;
        cout << "Updated!" << endl;
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

    void display() {
        cout << "Car details: " << endl;
        cout << "Brand Name: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Price: " << price << " $" << endl;
        cout << "Revenue: " << this->revenue << endl;
    }

      void rental_request() {
        if (availibility_status == 1) {
        availibility_status = 0;
        cout << "You have rented the car!" << endl;
        }
    }

    ~Car () {
        cout << "The car: " << brand << " has been destroyed" << endl;
    }
};

int main () {
    Car Honda("City", "2022", 8500);
    Honda.rental_request();
    Honda.Update_revenue();
    Honda.Availibility_status();
    Honda.Update_revenue();
    Honda.display();
    return 0;
} 
