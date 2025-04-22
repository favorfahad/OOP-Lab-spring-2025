// Name: Fahad Qureshi
// Roll No: 24K-0824

#include <iostream>
using namespace std;

class WeatherSensor {
    public:
    virtual void readData() = 0;
    virtual void displayReport() = 0;
};

class Thermometer : public WeatherSensor {
    public:
    void readData() override {
        cout << "Reading temperature: 32°C\n";
    }
    void displayReport() override {
        cout << "Temperature Report: Normal range\n";
    }
};

class Barometer : public WeatherSensor {
    public:
    void readData() override {
        cout << "Reading pressure: 1013 hPa\n";
    }
    void displayReport() override {
        cout << "Pressure Report: Stable conditions\n";
    }
};

int main() {
    WeatherSensor* sensors[] = {
        new Thermometer(),
        new Barometer()
    };

    for(WeatherSensor* s : sensors) {
        s->readData();
        s->displayReport();
        cout << endl;
        delete s;
    }
    return 0;
}
