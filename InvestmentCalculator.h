#ifndef INVESTMENTCALCULATOR_H
#define INVESTMENTCALCULATOR_H

class InvestmentCalculator {
private:
    double initialInvestment;
    double monthlyDeposit;
    double annualInterestRate;
    int years;

public:
    // Constructor
    InvestmentCalculator(double initialInvestment, double monthlyDeposit, double annualInterestRate, int years);

    // Methods to calculate and display investment growth
    void displayInputValues() const;
    void calculateYearEndBalanceWithoutDeposits() const;
    void calculateYearEndBalanceWithDeposits() const;
};

#endif

