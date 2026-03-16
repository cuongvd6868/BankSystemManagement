#include "Bank.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <fstream>

Account* Bank::findAccount(std::string id) {
    auto it = accounts.find(id);
    return (it != accounts.end()) ? it->second.get() : nullptr;
}

void Bank::createAccount(std::string accNum, std::string name, double bal, int type) {
    if (type == 1) 
        accounts[accNum] = std::make_unique<SavingsAccount>(accNum, name, bal, 0.05);
    else 
        accounts[accNum] = std::make_unique<CheckingAccount>(accNum, name, bal);
}

bool Bank::transfer(std::string fromId, std::string toId, double amount) {
    Account* sender = findAccount(fromId);
    Account* receiver = findAccount(toId);
    if (sender && receiver && sender->withdraw(amount)) {
        receiver->deposit(amount);
        return true;
    }
    return false;
}

void Bank::showAllAccounts() const {
    for (auto const& [id, acc] : accounts) {
        acc->displayInfo();
        std::cout << std::endl;
    }
}

void Bank::saveToDisk() {
    std::ofstream f(DATA_FILE);
    for (auto const& [id, acc] : accounts) {
        f << id << "|" << acc->getBalance() << "\n";
    }
}