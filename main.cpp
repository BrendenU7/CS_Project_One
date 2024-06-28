#include <iostream>
#include "InvestmentCalculator.h"

using namespace std;

int main() {
    // Declaring object/variables
    double initialInvestment, monthlyDeposit, annualInterestRate;
    int years;
    char choice;

    do {
        // Get user inputs
        cout << "Enter Initial Investment Amount: ";
        cin >> initialInvestment;
        cout << "Enter Monthly Deposit: ";
        cin >> monthlyDeposit;
        cout << "Enter Annual Interest Rate (in %): ";
        cin >> annualInterestRate;
        cout << "Enter Number of Years: ";
        cin >> years;

        // Create InvestmentCalculator object
        InvestmentCalculator calculator(initialInvestment, monthlyDeposit, annualInterestRate, years);

        // Display input values
        calculator.displayInputValues();

        // Calculate and display balances without monthly deposits
        calculator.calculateYearEndBalanceWithoutDeposits();

        // Calculate and display balances with monthly deposits
        calculator.calculateYearEndBalanceWithDeposits();

        // Ask user if they want to run another calculation
        cout << "Do you want to test different inputs? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
