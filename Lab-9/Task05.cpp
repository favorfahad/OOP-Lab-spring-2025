// Name: Fahad Qureshi
// Roll No: 24K-0824

#include <iostream>
using namespace std;

class Shipment {
    protected:
    string trackingNumber;
    double weight;
    public:
    Shipment(string tn, double w) : trackingNumber(tn), weight(w) {}
    virtual void estimateDeliveryTime() = 0;
    virtual void showDetails() = 0;
};

class AirFreight : public Shipment {
    public:
    AirFreight(string tn, double w) : Shipment(tn, w) {}
    void estimateDeliveryTime() override {
        cout << "Estimated air delivery: 2 days\n";
    }
    void showDetails() override {
        cout << "Air Freight #" << trackingNumber << " (" << weight << " kg)\n";
    }
};

class GroundShipment : public Shipment {
    public:
    GroundShipment(string tn, double w) : Shipment(tn, w) {}
    void estimateDeliveryTime() override {
        cout << "Estimated ground delivery: 5 days\n";
    }
    void showDetails() override {
        cout << "Ground Shipment #" << trackingNumber << " (" << weight << " kg)\n";
    }
};

int main() {
    Shipment* shipments[] = {
        new AirFreight("AF-1234", 150),
        new GroundShipment("GS-5678", 500)
    };

    for(Shipment* s : shipments) {
        s->showDetails();
        s->estimateDeliveryTime();
        cout << endl;
        delete s;
    }
    return 0;
}
