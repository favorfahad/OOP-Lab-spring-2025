/* Name: Fahad Qureshi
  Roll NO: 24K-0824 */

#include "iostream"
using namespace std;

class Ticket {
    protected:
    int ticketID;
    string passengerName;
    double price;
    string date;
    string destination;
    public:
    Ticket(int id, string name, double p, string d, string dest) : ticketID(id), passengerName(name), price(p), date(d), destination(dest) {}
    virtual void reserve() { cout << "Reserving ticket..." << endl; }
    virtual void cancel() { cout << "Canceling ticket..." << endl; }
    virtual void displayTicketInfo() {
        cout << "Ticket ID: " << ticketID << endl;
        cout << "Passenger: " << passengerName << endl;
        cout << "Price: $" << price << endl;
        cout << "Date: " << date << endl;
        cout << "Destination: " << destination << endl;
    }
};

class FlightTicket : public Ticket {
    private:
    string airlineName;
    string flightNumber;
    string seatClass;
    public:
    FlightTicket(int id, string name, double p, string d, string dest, string air, string fn, string sc) : Ticket(id, name, p, d, dest), airlineName(air), flightNumber(fn), seatClass(sc) {}
    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Airline: " << airlineName << endl;
        cout << "Flight Number: " << flightNumber << endl;
        cout << "Class: " << seatClass << endl;
    }
};

class TrainTicket : public Ticket {
    private:
    string trainNumber;
    string coachType;
    string departureTime;
    public:
    TrainTicket(int id, string name, double p, string d, string dest, string tn, string ct, string dt) : Ticket(id, name, p, d, dest), trainNumber(tn), coachType(ct), departureTime(dt) {}
    void reserve() override {
        cout << "Seat auto-assigned." << endl;
        Ticket::reserve();
    }
};

class BusTicket : public Ticket {
    private:
    string busCompany;
    string seatNumber;
    public:
    BusTicket(int id, string name, double p, string d, string dest, string bc, string sn) : Ticket(id, name, p, d, dest), busCompany(bc), seatNumber(sn) {}
    void cancel() override {
        cout << "Last-minute refund processed." << endl;
        Ticket::cancel();
    }
};

class ConcertTicket : public Ticket {
    private:
    string artistName;
    string venue;
    string seatType;
    public:
    ConcertTicket(int id, string name, double p, string d, string dest, string artist, string v, string st) : Ticket(id, name, p, d, dest), artistName(artist), venue(v), seatType(st) {}
    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Artist: " << artistName << endl;
        cout << "Venue: " << venue << endl;
        cout << "Seat Type: " << seatType << endl;
    }
};

int main() {
    FlightTicket flight(201, "John Doe", 299.99, "2023-10-05", "New York", "AirFast", "AF101", "Economy");
    TrainTicket train(202, "Jane Smith", 49.99, "2023-10-06", "Boston", "TR789", "Standard", "08:30");
    BusTicket bus(203, "Alice Brown", 19.99, "2023-10-07", "Chicago", "BusLine", "14B");
    ConcertTicket concert(204, "Bob White", 89.99, "2023-10-08", "LA Arena", "RockStar", "LA Arena", "VIP");

    cout << "--- Flight Ticket ---" << endl;
    flight.displayTicketInfo();
    cout << "\n--- Train Reservation ---" << endl;
    train.reserve();
    cout << "\n--- Bus Cancellation ---" << endl;
    bus.cancel();
    cout << "\n--- Concert Ticket ---" << endl;
    concert.displayTicketInfo();
    return 0;
}
