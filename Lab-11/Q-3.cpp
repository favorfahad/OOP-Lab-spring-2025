#include "iostream"
#include "exception"
using namespace std;

class InvalidTemperatureException : public exception {  
    string text;
    public:
    InvalidTemperatureException(const string &text) : text(text) {}

    void Error () {
        cout << text << endl;
    }
};

template<typename X>
void convertToFahrenheit(X celsius) {
    try {
        if (celsius < -273.15) throw InvalidTemperatureException("Caught InvalidTemperatureException");
        else {
            cout << "Attempting to convert " << celsius << "..." << endl;
        }
    }

    catch (InvalidTemperatureException &E) {
        E.Error();
    }
};

int main () {
    double temp = -280;
    convertToFahrenheit(temp);
    temp = 127;
    convertToFahrenheit(temp);
    return 0;
}
