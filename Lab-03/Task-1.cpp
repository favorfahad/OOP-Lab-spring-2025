/* Name: Fahad Qureshi
 ROll NO: 24K-0824
*/
#include<iostream>
#include<string>
using namespace std;

class Wallet {
    private:
     string OwnerName;
     int TotalAmount;
     string transactionhistory[500];
     int count; //for transaction

    public:
    Wallet() {
        OwnerName = "Saad";
        TotalAmount = 20000;
        count = 0;
        transactionhistory[count] = "Account created for: " + OwnerName + ", with inital balance of PKR " + to_string(TotalAmount);  
    }

    void setTotalAmount(int bal) {
        TotalAmount = bal;
    }
    string getOwnerName() {
        return OwnerName;
    }
    int getbalance() {
        return TotalAmount;
    }
    //getter for both attributes

    void Depositmoney(int money) {
        if (money > 0) {
            TotalAmount += money;
            count++;
            transactionhistory[count] = "Amount deposited: " + to_string(money) + " PKR, New Balance: " + to_string(TotalAmount);
            cout << "Amount added successfully!" << endl;
        } else {
            cout << "Invalid amount!" << endl;
        }
    }

    void SpendMoney(int money) {
        if (money > 0 && money <= TotalAmount) {
            TotalAmount -= money;
            count++;
            transactionhistory[count] = "Amount spent: " + to_string(money) + " PKR, New Balance: " + to_string(TotalAmount);
            cout << "Amount withdrawn!" << endl;
            if (TotalAmount < 5000) {
                cout << "Warning! YOU HAVE LOW BALANCE!" << endl;
            }
        } else {
            cout << "You have insufficient balance!" << endl;
        }
    }

    void displayhistory() {
        cout << "\nTransaction History for " << OwnerName << ":" << endl;
        for (int i=0;i<=count;i++) {
            cout << i+1 << " " << transactionhistory[i] << endl;
        }
    }
};

int main() {
    Wallet Saad_wallet;
    int opt, money;
    
while(1) {
    cout << "1. Add more money to the wallet." << endl;
    cout << "2. Spend money from the wallet. " << endl;
    cout << "3. Watch transaction history. " << endl;
    cout << "Choose from one of the above: " << endl;
    cin >> opt;
    switch (opt)
    {
    case 1:
    cout << "Enter the amount which you want to add: ";
    cin >> money;
    Saad_wallet.Depositmoney(money);
    break;
    case 2:
    cout << "Enter the amount which you want to take out: ";
    cin >> money;
    Saad_wallet.SpendMoney(money);
    break;
    case 3:
    Saad_wallet.displayhistory();
    break;
    default:
    cout << "Invalid option." << endl;
    break;
    }
        }
    return 0;
}
