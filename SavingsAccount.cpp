#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(std::string accNum, std::string name, double bal, double rate)
    : Account(accNum, name, bal), interestRate(rate) {}

bool SavingsAccount::withdraw(double amount) {
    if (amount > 0 && (balance - amount) >= 50000) {
        balance -= amount;
        return true;
    }
    return false;
}

void SavingsAccount::displayInfo() const {
    std::cout << "[Tiet kiem] ";
    Account::displayInfo();
    std::cout << " | Lai suat: " << interestRate * 100 << "%";
}