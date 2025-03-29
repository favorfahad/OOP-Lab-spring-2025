#include "iostream"
using namespace std;

class Device {
    private:
    int DeviceID;
    string DeviceName;
    bool status;
    string location;
    public:
    Device(int ID, string name, string location) : 
    DeviceID(ID), DeviceName(name), status(0), location(location) {}
    int getDeviceID() {return DeviceID;}
    virtual void turnOn() { status = 1; }
    virtual void turnOff() { status = 0; } 
    virtual void getStatus() { 
        if (status == 1)
            cout << "The device is on." << endl;
        else if (status == 0)
            cout << "The device is off." << endl;
    }
    virtual void displayinfo() {
        cout << "Device ID: " << DeviceID << endl << "Device Name: " << DeviceName << endl << "Current Location: " << location << endl;
    }
};

class Light : public Device {
    private:
    int BrightnessLevel; // from 0 to 10
    string colorMode;
    public:
    Light(int ID, string name, string location, int level, string mode) : 
    Device(ID, name, location), BrightnessLevel(level), colorMode(mode) {}

    void displayinfo () override {
        cout << "Brightness Level: " << BrightnessLevel << endl;
        cout << "Current Color Mode: " << colorMode << endl;
        cout << "Light ID: " << getDeviceID() << endl;
    }

};

class Thermostat : public Device {
    private:
    double Temperature;
    bool mode; // 0 for Cooling, 1 for heating 
    double targetTemperature;
    public:
    Thermostat(int ID, string name, string location, double temp, bool mode, double targetTemp) 
    : Device(ID, name, location), Temperature(temp), mode(mode), targetTemperature(targetTemp) {}
    
    void getStatus() override {
        cout << "Current Temperature: " << Temperature << endl; 
    }
};

class SecurityCamera : public Device {
    private:
    int resolution;
    bool recordingStatus;
    bool NightVisionEnabled;
    public:
    SecurityCamera(int ID, string name, string location, int resolution) :
    Device(ID, name, location), resolution(resolution), NightVisionEnabled(0), recordingStatus(0) {}

    void turnOn() override {
        recordingStatus = true;
    }
};

class SmartPlug : public Device { 
    private:
    double powerConsumption;
    string timerSetting;
    public:
    SmartPlug(int ID, string name, string location) : Device(ID, name, location), powerConsumption(0) {}

    void turnOff() override {
        double pow;
        cout << "Enter the power consumed so far (in kWh): ";
        cin >> pow;
        powerConsumption = pow;
    }
};

int main() {
    Light LED(244, "LED", "Kitchen", 7, "Orange");
    Thermostat thermostat(657, "Thermostat", "Laundry Room", 25, 0, 16);
    SecurityCamera Camera(321, "Nikon", "Hallway", 30);
    SmartPlug Plug(678, "Kawasaki", "Bedroom");

    LED.displayinfo();
    thermostat.getStatus();
    Camera.turnOn();
    Plug.turnOff();

    return 0;
}
