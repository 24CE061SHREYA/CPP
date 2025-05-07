#include <iostream>
#include <limits>  // for numeric_limits
using namespace std;

// Function to get valid double input from user
double getValidatedInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear();  // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // discard invalid input
            cout << "Invalid input. Please enter a numeric value.\n";
        } else {
            return value;
        }
    }
}

int main() {
    cout << "--- Loan-to-Income Ratio Calculator ---\n";

    double loanAmount = getValidatedInput("Enter the total loan amount: ₹");
    double annualIncome;

    // Ensure income is not zero
    while (true) {
        annualIncome = getValidatedInput("Enter your annual income: ₹");
        if (annualIncome == 0) {
            cout << "Income cannot be zero. Please enter a valid annual income.\n";
        } else {
            break;
        }
    }

    // Calculate and display ratio
    double ratio = loanAmount / annualIncome;

    cout << "\nLoan-to-Income Ratio: " << ratio << endl;

    // Optional: Interpret the result
    if (ratio > 0.4)
        cout << "Warning: Your loan-to-income ratio is high. Loan approval may be at risk.\n";
    else
        cout << "Good: Your loan-to-income ratio is within an acceptable range.\n";

    return 0;
}

