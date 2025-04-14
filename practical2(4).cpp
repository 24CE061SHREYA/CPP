#include <iostream>
using namespace std;

class InventoryItem
{
    string itemID, itemName;
    int price, quantity;

public:
    InventoryItem()
    {
        price = 0;
        quantity = 0;
    }

    InventoryItem(string ID, string Name, int p, int q)
    {
        itemID = ID;
        itemName = Name;
        price = p;
        quantity = q;
    }

    void display() const
    {
        cout << "\nProduct name is: " << itemName;
        cout << "\nProduct ID is: " << itemID;
        cout << "\nProduct's Quantity is: " << quantity;
        cout << "\nProduct price is: " << price << endl;
    }

    void addStock(int qty)
    {
        quantity += qty;
    }

    bool sellItem(int qty)
    {
        if (quantity >= qty)
        {
            quantity -= qty;
            return true;
        }
        else
        {
            cout << "\nInsufficient stock to sell!" << endl;
            return false;
        }
    }

    bool isMatch(const string &ID) const
    {
        return itemID == ID;
    }
};

int main()
{
    string ID, Name, i_id;
    int p, q, n, option;

    cout << "Enter number of items: ";
    cin >> n;

    InventoryItem items[100];

    for (int j = 0; j < n; j++)
    {
        cout << "\nDetails of product " << j + 1 << ":";
        cout << "\nEnter product name: ";
        cin >> Name;
        cout << "Enter product ID: ";
        cin >> ID;
        cout << "Enter product price: ";
        cin >> p;
        cout << "Enter product quantity: ";
        cin >> q;
        items[j] = InventoryItem(ID, Name, p, q);
    }

    while (true)
    {
        cout << "\n\nMenu for operations:";
        cout << "\n1. Add quantity";
        cout << "\n2. Sell item";
        cout << "\n3. Display all items";
        cout << "\n0. Exit";
        cout << "\nEnter item ID and option: ";
        cin >> i_id >> option;

        if (option == 0)
        {
            break;
        }

        bool found = false;

        for (int j = 0; j < n; j++)
        {
            if (items[j].isMatch(i_id))
            {
                found = true;

                switch (option)
                {
                case 1:
                {
                    int Q;
                    cout << "Enter quantity to increase: ";
                    cin >> Q;
                    items[j].addStock(Q);
                    cout << "\nStock updated successfully!";
                }
                break;

                case 2:
                {
                    int Q1;
                    cout << "Enter quantity to sell: ";
                    cin >> Q1;
                    if (items[j].sellItem(Q1))
                    {
                        cout << "\nItem sold successfully!";
                    }
                }
                break;

                case 3:
                {
                    for (int k = 0; k < n; k++)
                    {
                        cout << "\nItem " << k + 1 << ":";
                        items[k].display();
                    }
                }
                break;

                default:
                    cout << "\nInvalid option!";
                    break;
                }
                break;
            }
        }

        if (!found)
        {
            cout << "\nItem ID not found!";
        }
    }

    cout << "\n\n24ce061_Shreya_Loriya";
    return 0;
}

