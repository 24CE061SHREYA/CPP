

#include <iostream>
#include <string>
using namespace std;

class Inventory {
private:
    int id[100];
    string name[100];
    int quantity[100];
    double price[100];
    int count;

public:

    Inventory() : count(0) {}


    void addProduct() {
        cout << "Enter details for product " << count + 1 << ":\n";
        cout << "ID: ";
        cin >> id[count];
        cin.ignore();

        cout << "Name: ";
        getline(cin, name[count]);

        cout << "Quantity: ";
        cin >> quantity[count];

        cout << "Price: ";
        cin >> price[count];

        count++;
    }


    void updateQuantity(int searchId, int qty) {
        for (int i = 0; i < count; i++) {
            if (id[i] == searchId) {
                quantity[i] += qty;
                cout << "Quantity updated for product ID " << searchId << "!" << endl;
                return;
            }
        }
        cout << "Product with ID " << searchId << " not found!" << endl;
    }


    void calculateTotalValue() {
        double total = 0;
        for (int i = 0; i < count; i++) {
            total += quantity[i] * price[i];
        }
        cout << "Total Inventory Value: " << total << endl;
    }


    void displayInventory() {
        cout << "Inventory Details:\n";
        for (int i = 0; i < count; i++) {
            cout << "ID: " << id[i]
                 << ", Name: " << name[i]
                 << ", Quantity: " << quantity[i]
                 << ", Price: " << price[i] << endl;
        }
    }
};

int main() {
    Inventory inventory;
    int numProducts;

    cout << "Enter the number of products to add: ";
    cin >> numProducts;

    for (int i = 0; i < numProducts; i++) {
        inventory.addProduct();
    }

    cout << "\nInventory after adding products:\n";
    inventory.displayInventory();

    int updateId, updateQty;
    cout << "\nEnter the ID of the product to update quantity: ";
    cin >> updateId;
    cout << "Enter the quantity to add: ";
    cin >> updateQty;

    inventory.updateQuantity(updateId, updateQty);

    cout << "\nInventory after updating quantity:\n";
    inventory.displayInventory();

    inventory.calculateTotalValue();


    return 0;
}
