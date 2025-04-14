#include <iostream>
using namespace std;

class Employee {
    string name;
    float basicSalary;
    float bonus;

public:
    Employee(string n, float bSalary, float bns = 1000.0f) {
        name = n;
        basicSalary = bSalary;
        bonus = bns;
    }

    inline float totalSalary() {
        return basicSalary + bonus;
    }

    void display() {
        cout << "........................................" << endl;
        cout << "Name: " << name << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Salary: " << totalSalary() << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    Employee* employees[n];

    for (int i = 0; i < n; ++i) {
        string name;
        float salary, bonus;
        char customBonus;

        cout << "\nEnter name of employee " << i + 1 << ": ";
        cin >> name;
        cout << "Enter basic salary: ";
        cin >> salary;
        cout << "Does this employee have a custom bonus? (y/n): ";
        cin >> customBonus;

        if (customBonus == 'y' || customBonus == 'Y') {
            cout << "Enter bonus: ";
            cin >> bonus;
            employees[i] = new Employee(name, salary, bonus);
        } else {
            employees[i] = new Employee(name, salary);
        }
    }

    cout << "\n--- Employee Details ---\n";
    for (int i = 0; i < n; ++i) {
        employees[i]->display();
    }

    for (int i = 0; i < n; ++i) {
        delete employees[i];
    }

    cout << "\n\n24ce061_Shreya_Loriya";
    return 0;
}
