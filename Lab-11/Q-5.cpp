#include <iostream>
#include <exception>
using namespace std;

class NegativeStockException : public exception {};
class OverCapacityException : public exception {};

template <typename T>
class InventoryItem {
private:
    T stock;
    T maxCapacity;

public:
    InventoryItem(T max) : maxCapacity(max), stock(0) {}

    void setStock(T newStock) {
        if (newStock < 0) {
            throw NegativeStockException();
        }
        if (newStock > maxCapacity) {
            throw OverCapacityException();
        }
        stock = newStock;
        cout << "Stock set to " << stock << endl;
    }
};

int main() {
    InventoryItem<int> item(100);

    try {
        cout << "Attempting to set stock to -5..." << endl;
        item.setStock(-5);
    } catch (const NegativeStockException& e) {
        cout << "Caught NegativeStockException - what(): " << e.what() << endl;
    }

    try {
        cout << "Attempting to set stock to 120 (max 100)..." << endl;
        item.setStock(120);
    } catch (const OverCapacityException& e) {
        cout << "Caught OverCapacityException - what(): " << e.what() << endl;
    }

    return 0;
}
