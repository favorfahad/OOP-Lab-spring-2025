/* Name: Fahad Qureshi
 ROll NO: 24K-0824
*/
#include<iostream>
#include<string>
using namespace std;

class Library {
    private:
    struct Booklist {
        string title;
        string author;
        int pages;
    };
    int availablebooks;
    int borrowedbooks;
    int count;
    string history[500];

    public:
    Booklist Book[100];
    Library() {
        availablebooks = 3;
        borrowedbooks = 0;
        count = 3;
        Book[0].author = "Dave";
        Book[1].author = "Hussain";
        Book[2].author = "James";
        Book[0].title = "Diary of a whimpy kid";
        Book[1].title = "History of Pakistan";
        Book[2].title = "Atomic Habits";
        Book[0].pages = 198;
        Book[2].pages = 259;
        Book[1].pages = 315;
        history[count] = "Library has been opened with three books initially.";
    }

    void addbooks(int n) {
        n += count;
        for(int i=count++;i<n;i++) {
            cin.ignore();
            cout << "Enter the title for book " << i << " of the library: ";
            getline(cin, Book[i].title);
            cout << "Enter the name of author for book " << i << " of the library: ";
            getline(cin, Book[i].author);
            cout << "Enter the total number of pages for book " << i << " of the library: ";
            cin >> Book[i].pages;
            availablebooks++;
            cout << "The books were successfully added." << endl;
        }
        count++;
        history[count] = to_string(n) + " books were added to the library,";
    }

    void lendbooks() {
        string Bookname;
        cout << "Enter the name of book you want to borrow: ";
        cin.ignore();
        getline(cin, Bookname); 
        if (availablebooks > 0) {
            for (int i=0;i<availablebooks;i++) {
                if (Bookname == Book[i].title) {
                    cout << "You have borrowed " << Bookname << ". Kindly return it on time." << endl;
                    borrowedbooks++;
                    count++;
                    history[count] = "The book: " + Bookname + " was borrowed from the library.";
                } else {
                    count++;
                    history[count] = "An attempt to borrow the book was failed due to unavailability!";
                    cout << "The required book is not available!" << endl;
                }
            }
        } else {
            cout << "There are currently no books in the library";
        }
    }

    void returnbooks() {
        if (borrowedbooks == 0) {
            cout << "There are no books to be returned.";
        } else {
            string name;
            cout << "Enter the title of the book you want to return: ";
            cin.ignore();
            getline(cin, name);
            borrowedbooks--;
            cout << "The book is returned." << endl;
            count++;
            history[count] = "The book: " + name + " was returned to the library.";
        }
    }

    void inventoryhistory() {
        cout << "Below is the history of library's inventory: " << endl;
        for (int i=0;i<=count;i++) {
            cout << history[i] << endl;
        }
        cout << endl;
    }

};

int main () {
    Library Hamza_Library;
    int opt, quantity;
    
while(1) {
    cout << "1. Add books to the library." << endl;
    cout << "2. Lend book from the library." << endl;
    cout << "3. Return book to the library." << endl;
    cout << "4. Watch the inventory's history." << endl;
    cout << "Choose from one of the above: " << endl;
    cin >> opt;
    switch (opt)
    {
    case 1:
    cout << "Enter the number of books which you want to add in the library: ";
    cin >> quantity;
    Hamza_Library.addbooks(quantity);
    break;
    case 2:
    Hamza_Library.lendbooks();
    break;
    case 3:
    Hamza_Library.returnbooks();
    break;
    case 4:
    Hamza_Library.inventoryhistory();
    break;
    default:
    cout << "Invalid option." << endl;
    break;
    }
  }
    return 0;
}
