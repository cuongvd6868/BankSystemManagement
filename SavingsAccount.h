#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
private:
    double interestRate;
public:
    SavingsAccount(std::string accNum, std::string name, double bal, double rate);
    bool withdraw(double amount) override;
    void displayInfo() const override;
};

#endif