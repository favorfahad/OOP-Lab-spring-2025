// Name: Fahad Qureshi
// Roll No: 24K-0824

#include <iostream>
using namespace std;

class Patient {
    private:
    string name;
    string id;
    public:
    Patient(string n, string i) : name(n), id(i) {}
    virtual void displayTreatment() = 0;
    virtual double calculateCost() = 0;
};

class InPatient : public Patient {
    public:
    InPatient(string n, string i) : Patient(n, i) {}
    void displayTreatment() override {
        cout << "Inpatient: ICU monitoring + surgery\n";
    }
    double calculateCost() override {
        return 150000.0;
    }
};

class OutPatient : public Patient {
    public:
    OutPatient(string n, string i) : Patient(n, i) {}
    void displayTreatment() override {
        cout << "Outpatient: Consultation + medication\n";
    }
    double calculateCost() override {
        return 5000.0;
    }
};

int main() {
    Patient* patients[] = {
        new InPatient("Ali Khan", "P001"),
        new OutPatient("Sara Ahmed", "P002")
    };

    for(Patient* p : patients) {
        p->displayTreatment();
        cout << "Cost: Rs " << p->calculateCost() << "\n\n";
        delete p;
    }
    return 0;
}
