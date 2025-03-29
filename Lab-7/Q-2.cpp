#include <iostream>
using namespace std;

class Product {
    private:
    int productID;
    string productName;
    double price;
    int stockQuantity;
    public:
    Product(int id, string name, double p, int sq) : productID(id), productName(name), price(p), stockQuantity(sq) {}
    virtual void applyDiscount() {}
    virtual double calculateTotalPrice(int quantity) { return price * quantity; }
    virtual void displayProductInfo() {
        cout << "Product ID: " << productID << endl;
        cout << "Name: " << productName << endl;
        cout << "Price: $" << price << endl;
        cout << "Stock Quantity: " << stockQuantity << endl;
    }
    int getProductID() { return productID; }
    string getProductName() { return productName; }
    double getPrice() { return price; }
    int getStockQuantity() { return stockQuantity; }
    void setPrice(double p) { price = p; }
};

class Electronics : public Product {
    private:
    int warrantyPeriod;
    string brand;
    public:
    Electronics(int id, string name, double p, int sq, int wp, string b) : Product(id, name, p, sq), warrantyPeriod(wp), brand(b) {}
    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "Warranty Period: " << warrantyPeriod << " months" << endl;
        cout << "Brand: " << brand << endl;
    }
};

class Clothing : public Product {
    private:
    string size;
    string color;
    string fabricMaterial;
    public:
    Clothing(int id, string name, double p, int sq, string s, string c, string fm) : Product(id, name, p, sq), size(s), color(c), fabricMaterial(fm) {}
    void applyDiscount() override {
        setPrice(getPrice() * 0.8);
    }
};

class FoodItem : public Product {
    private:
    string expirationDate;
    int calories;
    public:
    FoodItem(int id, string name, double p, int sq, string ed, int cal) : Product(id, name, p, sq), expirationDate(ed), calories(cal) {}
    double calculateTotalPrice(int quantity) override {
        if (quantity > 10) return getPrice() * quantity * 0.9;
        return getPrice() * quantity;
    }
};

class Book : public Product {
    private:
    string author;
    string genre;
    public:
    Book(int id, string name, double p, int sq, string a, string g) : Product(id, name, p, sq), author(a), genre(g) {}
    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
    }
};

double operator+(Product& a, Product& b) {
    return a.getPrice() + b.getPrice();
}

ostream& operator<<(ostream& os, Product& p) {
    p.displayProductInfo();
    return os;
}

int main() {
    Electronics laptop(101, "Laptop", 999.99, 5, 24, "TechBrand");
    Clothing shirt(102, "Shirt", 29.99, 10, "M", "Blue", "Cotton");
    FoodItem apple(103, "Apple", 0.99, 100, "2023-12-31", 95);
    Book novel(104, "Novel", 14.99, 20, "Author Name", "Fiction");

    cout << "--- Electronics Info ---" << endl;
    cout << laptop;
    cout << "\n--- Clothing Discount Applied ---" << endl;
    shirt.applyDiscount();
    cout << shirt;
    cout << "\n--- Food Bulk Price ---" << endl;
    cout << "Total for 15 apples: $" << apple.calculateTotalPrice(15) << endl;
    cout << "\n--- Book Details ---" << endl;
    cout << novel;

    cout << "\nCombined price of laptop and book: $" << (laptop + novel) << endl;
    return 0;
}
