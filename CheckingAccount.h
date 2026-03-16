#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account {
public:
    CheckingAccount(std::string accNum, std::string name, double bal);
    bool withdraw(double amount) override;
    void displayInfo() const override;
};

#endif