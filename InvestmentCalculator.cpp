#include <iostream>
#include <iomanip>
#include "InvestmentCalculator.h"

using namespace std;

// Constructor to initialize the InvestmentCalculator with given values
InvestmentCalculator::InvestmentCalculator(double initialInvestment, double monthlyDeposit, double annualInterestRate, int years) {
    this->initialInvestment = initialInvestment; 
    this->monthlyDeposit = monthlyDeposit; 
    this->annualInterestRate = annualInterestRate; 
    this->years = years; 
}

// Function to display the input values provided by the user
void InvestmentCalculator::displayInputValues() const {
    cout << "Initial Investment Amount: $" << initialInvestment << endl;
    cout << "Monthly Deposit: $" << monthlyDeposit << endl;
    cout << "Annual Interest: %" << annualInterestRate << endl;
    cout << "Number of Years: " << years << endl;
    cout << "Press any key to continue..." << endl;
    cin.get(); // Wait for user input
}

// Function to calculate and display the year-end balance without additional monthly deposits
void InvestmentCalculator::calculateYearEndBalanceWithoutDeposits() const {
    double balance = initialInvestment; 
    cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << "Year\tYear End Balance\tYear End Earned Interest" << endl;

    // Loop through each year and calculate the balance and interest
    for (int year = 1; year <= years; ++year) {
        double interest = balance * (annualInterestRate / 100); // Calculate yearly interest
        balance += interest; // Add the interest to the balance
        cout << year << "\t$" << fixed << setprecision(2) << balance << "\t\t$" << interest << endl; // Display the year, balance, and interest
    }
}

// Function to calculate and display the year-end balance with additional monthly deposits
void InvestmentCalculator::calculateYearEndBalanceWithDeposits() const {
    double balance = initialInvestment; 
    cout << "Balance and Interest With Additional $" << monthlyDeposit << " Monthly Deposits" << endl;
    cout << "Year\tYear End Balance\tYear End Earned Interest" << endl;

    // Loop through each year
    for (int year = 1; year <= years; ++year) {
        double yearEndInterest = 0; // Initialize yearly interest

        // Loop through each month
        for (int month = 1; month <= 12; ++month) {
            balance += monthlyDeposit; // Add monthly deposit to balance
            double interest = balance * ((annualInterestRate / 100) / 12); // Calculate monthly interest
            yearEndInterest += interest; // Accumulate monthly interest to yearly interest
            balance += interest; // Add monthly interest to balance
        }
        // Display the year, balance, and yearly interest
        cout << year << "\t$" << fixed << setprecision(2) << balance << "\t\t$" << yearEndInterest << endl;
    }
}
