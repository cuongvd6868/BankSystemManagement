#include "Account.h"

Account::Account(std::string accNum, std::string name, double initialBalance)
    : accountNumber(accNum), ownerName(name), balance(initialBalance) {}

Account::~Account() {}

void Account::deposit(double amount) {
    if (amount > 0) balance += amount;
}

void Account::displayInfo() const {
}

std::string Account::getAccNum() const { return accountNumber; }
double Account::getBalance() const { return balance; }