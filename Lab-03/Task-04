/* Name: Fahad Qureshi
 ROll NO: 24K-0824
*/
#include<iostream>
#include<string>
using namespace std;

class Car {
    private:
    string brand;
    string model;
    float FuelCapacity;
    float CurrentFuelLevel;   //considering both in litres

    public:
    Car (string Brand, string Model, float FC, float CFC) { 
        brand = Brand;
        model = Model;
        FuelCapacity = FC;
        CurrentFuelLevel = CFC;
    }

    void Distancedriven(float distance) {
      if (distance < 0 || (distance/15) >= CurrentFuelLevel) {
            cout << "Enter a valid distance." << endl;
        } else {
            CurrentFuelLevel -= (distance/15); //assuming that the car gives an average of 15 km per litre
            if (CurrentFuelLevel < 5) {
                cout << "Your car will be running out of the fuel soon!" << endl;
            }
            cout << "Your car's fuel has been adjusted!" << endl;
        }
    }

    void Refuling(float litres) {
        if (litres < 0 || (litres+CurrentFuelLevel) > FuelCapacity) {
            cout << "The car can not be filled with such amount!" << endl;
        } else {
            CurrentFuelLevel += litres;
            cout << litres << " litres of fuel has been filled in the car." << endl;
        }
    }

    void Checkfuelstatus() {
        cout << "Your car has " << CurrentFuelLevel << " litres of fuel at the moment" << endl;
        if (CurrentFuelLevel < 5) {
                cout << "Your car will be running out of the fuel soon!" << endl;
        }
    }
};

int main () {
    int opt;
    string Name, Model;
    float CurrentFuel, FuelCapacity;

    cout << "Enter the name of your car: ";
    getline(cin, Name);
    cout << "ENter the model name of your car: ";
    getline(cin, Model);
    cout << "Enter the current fuel level of your car: ";
    cin >> CurrentFuel;
    cout << "Enter the total fuel capacity of your car: ";
    cin >> FuelCapacity;
    Car Zoyas_Car(Name, Model, FuelCapacity, CurrentFuel);

while(1) {
    cout << "1. Modify the fuel level after driving the car." << endl;
    cout << "2. Refule the car." << endl;
    cout << "3. Check current fuel status." << endl;
    cout << "Choose from one of the above: " << endl;
    cin >> opt;
    switch (opt)
    {
    case 1:
    float distance;
    cout << "Enter the distance driven by your car: ";
    cin >> distance;
    Zoyas_Car.Distancedriven(distance);
    break;
    case 2:
    float qty;
    cout << "Enter the quantity of fuel filled into the car: ";
    cin >> qty;
    Zoyas_Car.Refuling(qty);
    break;
    case 3:
    Zoyas_Car.Checkfuelstatus();
    break;
    default:
    cout << "Invalid option." << endl;
    break;
    }
  }
    return 0;
}
