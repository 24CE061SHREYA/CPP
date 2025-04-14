#include <iostream>
using namespace std;

class bank {
    string name;
    int account_number;
    int balance;

public:
    int data(int acc1) {
        if (acc1 == account_number) {
            put();
            return 0;
        }
        return -1;
    }

    void get();
    void put();
    void deposit_amount();
    void withdraw_amount();
};

void bank::get() {
    cout << "\nEnter Name: ";
    cin >> name;
    cout << "Enter Account Number: ";
    cin >> account_number;
    cout << "Enter Current Balance: ";
    cin >> balance;
}

void bank::put() {
    cout << "\nThe Account Name is: " << name;
    cout << "\nThe Final Balance is: " << balance << endl;
}

void bank::deposit_amount() {
    int d;
    cout << "Enter the amount you want to deposit: ";
    cin >> d;
    balance += d;
}

void bank::withdraw_amount() {
    int w;
    cout << "Enter the amount you want to withdraw: ";
    cin >> w;
    if (w > balance) {
        cout << "Insufficient balance!" << endl;
    } else {
        balance -= w;
    }
}

int main() {
    int h, acc;

    cout << "Enter the number of accounts you want to create: ";
    cin >> h;

    bank b[100];
    for (int i = 0; i < h; i++) {
        cout << "\nEnter details for account " << i + 1 << ":";
        b[i].get();
    }

    cout << "\nEnter the account number to retrieve details: ";
    cin >> acc;

    bool found = false;
    for (int i = 0; i < h; i++) {
        if (b[i].data(acc) == 0) {
            found = true;
            b[i].deposit_amount();
            b[i].withdraw_amount();
            b[i].put();
            break;
        }
    }

    if (!found) {
        cout << "Account not found!" << endl;
    }

    cout << "\n\n24ce061_Shreya_Loriya\n";
    return 0;
}
