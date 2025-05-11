#include <iostream>
#include <exception>
using namespace std;

class InvalidTemperatureException : public exception {};

template<typename X>
void convertToFahrenheit(X celsius) {
    try {
        if (celsius < -273.15) throw InvalidTemperatureException();
        cout << "Attempting to convert " << celsius << "C..." << endl;
    } catch (const InvalidTemperatureException& e) {
        cout << "Caught InvalidTemperatureException - what(): " << e.what() << endl;
    }
}

int main() {
    double temp = -300;
    convertToFahrenheit(temp);
    temp = 127;
    convertToFahrenheit(temp);
    return 0;
}
