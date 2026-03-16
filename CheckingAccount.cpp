#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(std::string accNum, std::string name, double bal) 
    : Account(accNum, name, bal) {}

bool CheckingAccount::withdraw(double amount) {
    double fee = 1100.0; // Phí giao dịch cố định
    if (amount > 0 && balance >= (amount + fee)) {
        balance -= (amount + fee);
        return true;
    }
    return false;
}

void CheckingAccount::displayInfo() const {
    std::cout << "[Thanh toan] ";
    Account::displayInfo();
    std::cout << " | Phi GD: 1.1k";
}