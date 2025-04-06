/* Name: Fahad Qureshi
    Roll No: 24K-0824 */
#include "iostream"
using namespace std;

class Account {
    private:
    long long int accountNumber;
    long double Balance;
    public:
    Account(long long int acc) : accountNumber(acc), Balance(0) {}
    friend class Manager;
    friend void transferFunds(Account&A1, Account&A2);
};

class Manager {
    public:
    void withdrawAmount(long double amount, Account &A) {
        if (amount <= A.Balance) {
            A.Balance -= amount;
            cout << "The amount " << amount << " has been withdrawn from the account." << endl;
        } else {cout << "There is unsufficient balance in the account." << endl;}
    }

    void depositAmount(long double amount, Account &A){
            A.Balance += amount;
            cout << "The amount " << amount << " has been deposited into the account." << endl;
    }

    void displayDetails(Account &A) {
        cout << "Account Number: " << A.accountNumber << endl;
        cout << "Account Balance: " << A.Balance << endl;
    }
};

void transferFunds(Account &A1, Account &A2) { //Assume that we have to transfer from A2 to A1
    long double amount;
    cout << "Enter the amount which you want to transfer: "; cin >> amount;
    if (A2.Balance >= amount) {
        A1.Balance += amount;
        A2.Balance -= amount;
        cout << "The transfer was successful." << endl;
    } else {
        cout << "There is unsufficient Balance in the account." << endl;
    }
}

int main () {
    Account Aslam(9811901);
    Account Afifa(76422292);
    Manager Sheikh;

    Sheikh.depositAmount(5000000, Aslam);
    Sheikh.depositAmount(800000, Afifa);

    transferFunds(Aslam, Afifa);

    Sheikh.withdrawAmount(45000, Aslam);
    Sheikh.displayDetails(Afifa);

    return 0;
}
