#include "iostream"
using namespace std;

class Person {
    protected:
    string name;
    int age;
    string contactNumber;
    string address;
    public:
    Person(string n, int a, string cn, string addr) : name(n), age(a), contactNumber(cn), address(addr) {}
    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Contact: " << contactNumber << endl;
        cout << "Address: " << address << endl;
    }
    virtual void updateInfo() { cout << "Updating information..." << endl; }
};

class Patient : public Person {
    private:
    int patientID;
    string medicalHistory;
    string doctorAssigned;
    public:
    Patient(string n, int a, string cn, string addr, int pid, string mh, string da) : Person(n, a, cn, addr), patientID(pid), medicalHistory(mh), doctorAssigned(da) {}
    void displayInfo() override {
        Person::displayInfo();
        cout << "Patient ID: " << patientID << endl;
        cout << "Medical History: " << medicalHistory << endl;
        cout << "Doctor: " << doctorAssigned << endl;
    }
};

class Doctor : public Person {
    private:
    string specialization;
    double consultationFee;
    string patientList;
    public:
    Doctor(string n, int a, string cn, string addr, string spec, double cf, string pl) : Person(n, a, cn, addr), specialization(spec), consultationFee(cf), patientList(pl) {}
    void displayInfo() override {
        Person::displayInfo();
        cout << "Specialization: " << specialization << endl;
        cout << "Consultation Fee: $" << consultationFee << endl;
        cout << "Patient List: " << patientList << endl;
    }
};

class Nurse : public Person {
    private:
    string assignedWard;
    string shiftTimings;
    public:
    Nurse(string n, int a, string cn, string addr, string ward, string shift) : Person(n, a, cn, addr), assignedWard(ward), shiftTimings(shift) {}
    void displayInfo() override {
        Person::displayInfo();
        cout << "Assigned Ward: " << assignedWard << endl;
        cout << "Shift Timings: " << shiftTimings << endl;
    }
};

class Administrator : public Person {
    private:
    string department;
    double salary;
    public:
    Administrator(string n, int a, string cn, string addr, string dept, double sal) : Person(n, a, cn, addr), department(dept), salary(sal) {}
    void updateInfo() override {
        cout << "Administrator data updated." << endl;
    }
};

int main() {
    Patient patient("Mike Johnson", 35, "555-1234", "123 Elm St", 301, "Allergies", "Dr. Smith");
    Doctor doctor("Dr. Smith", 45, "555-5678", "456 Oak St", "Cardiology", 150.0, "Mike Johnson, Alice Brown");
    Nurse nurse("Nurse Claire", 28, "555-9012", "789 Pine St", "Emergency", "Night Shift");
    Administrator admin("Admin Bob", 50, "555-3456", "321 Maple St", "HR", 45000.0);

    cout << "--- Patient Info ---" << endl;
    patient.displayInfo();
    cout << "\n--- Doctor Info ---" << endl;
    doctor.displayInfo();
    cout << "\n--- Nurse Info ---" << endl;
    nurse.displayInfo();
    cout << "\n--- Administrator Update ---" << endl;
    admin.updateInfo();
    return 0;
}
