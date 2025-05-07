#include <iostream>
#include <string>
using namespace std;

// Base Class
class BankAccount {
protected:
    int accountNumber;
    double balance;

public:
    BankAccount(int accNum, double bal) : accountNumber(accNum), balance(bal) {
        cout << "BankAccount constructor called\n";
    }

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << "\n";
    }

    virtual void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds!\n";
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << "\n";
        }
    }

    virtual void display() {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << "\n";
    }

    virtual ~BankAccount() {
        cout << "BankAccount destructor called\n";
    }
};

// Derived Class: SavingsAccount
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(int accNum, double bal, double rate)
        : BankAccount(accNum, bal), interestRate(rate) {
        cout << "SavingsAccount constructor called\n";
    }

    void display() override {
        BankAccount::display();
        cout << "Interest Rate: " << interestRate << "%\n";
    }

    ~SavingsAccount() {
        cout << "SavingsAccount destructor called\n";
    }
};

// Derived Class: CurrentAccount
class CurrentAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CurrentAccount(int accNum, double bal, double limit)
        : BankAccount(accNum, bal), overdraftLimit(limit) {
        cout << "CurrentAccount constructor called\n";
    }

    void withdraw(double amount) override {
        if (amount > balance + overdraftLimit) {
            cout << "Exceeded overdraft limit!\n";
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << "\n";
        }
    }

    void display() override {
        BankAccount::display();
        cout << "Overdraft Limit: " << overdraftLimit << "\n";
    }

    ~CurrentAccount() {
        cout << "CurrentAccount destructor called\n";
    }
};

// Manual Stack for Transactions
class TransactionStack {
private:
    double history[100];
    int top;

public:
    TransactionStack() : top(-1) {}

    void push(double val) {
        if (top < 99)
            history[++top] = val;
        else
            cout << "Transaction history full!\n";
    }

    double pop() {
        if (top >= 0)
            return history[top--];
        else {
            cout << "No transaction to undo!\n";
            return 0;
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

// Unified Banking System (can use either type of account)
void bankingSystem(bool useSavings) {
    TransactionStack trans;
    BankAccount* acc;

    if (useSavings)
        acc = new SavingsAccount(101, 1000.0, 4.5);
    else
        acc = new CurrentAccount(202, 500.0, 300.0);

    int choice;
    double amount;

    do {
        cout << "\nBanking Menu:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Undo Last Transaction\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter deposit amount: ";
            cin >> amount;
            acc->deposit(amount);
            trans.push(-amount); // For undo deposit
            break;
        case 2:
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            acc->withdraw(amount);
            trans.push(amount);  // For undo withdrawal
            break;
        case 3:
            if (!trans.isEmpty()) {
                double last = trans.pop();
                if (last < 0) {
                    acc->withdraw(-last);
                    cout << "Undo Deposit of " << -last << "\n";
                } else {
                    acc->deposit(last);
                    cout << "Undo Withdrawal of " << last << "\n";
                }
            }
            break;
        case 4:
            acc->display();
            break;
        }
    } while (choice != 5);

    delete acc;
}

// Main Function
int main() {
    int choice;
    cout << "Choose Account Type:\n";
    cout << "1. Savings Account\n";
    cout << "2. Current Account\n";
    cout << "Choice: ";
    cin >> choice;

    if (choice == 1)
        bankingSystem(true);
    else if (choice == 2)
        bankingSystem(false);
    else
        cout << "Invalid choice.\n";

    return 0;
}
