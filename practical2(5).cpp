#include <iostream>
#include <cmath>
using namespace std;

class Loan {
    int loanId;
    string name;
    float amt;
    float rate;
    int tenure;
    float EMI;

public:
    Loan() {
        loanId = 0;
        amt = 0;
        rate = 0;
        tenure = 0;
    }

    Loan(int a, string b, float c, float d, int e) {
        loanId = a;
        name = b;
        amt = c;
        rate = d;
        tenure = e;
    }

    float calculateEMI() {
        double p = pow((1 + rate), tenure);
        float emi = ((amt * rate) * p) / (p - 1);
        cout << "EMI is " << emi << endl;
        EMI = emi;
        return emi;
    }

    void display() {
        cout << "**************************" << endl;
        cout << "Loan ID : " << loanId << endl;
        cout << "Name : " << name << endl;
        cout << "Amount : " << amt << endl;
        cout << "Rate : " << rate << endl;
        cout << "Tenure : " << tenure << endl;
        cout << "EMI : " << EMI << endl;
    }
};

int main() {
    int loanid;
    string name;
    float amt;
    float rate;
    int tenure;

    cout << "Enter Loan ID: ";
    cin >> loanid;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Amount of Loan: ";
    cin >> amt;
    cout << "Enter Rate of Interest: ";
    cin >> rate;
    cout << "Enter Tenure of Loan (in years): ";
    cin >> tenure;

    Loan y1(loanid, name, amt, rate, tenure);
    y1.calculateEMI();
    y1.display();

    cout << "\n\n24ce061_Shreya_Loriya";
    return 0;
}

