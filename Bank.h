#ifndef BANK_H
#define BANK_H

#include <map>
#include <memory>
#include "Account.h"

class Bank {
private:
    std::map<std::string, std::unique_ptr<Account>> accounts;
    const std::string DATA_FILE = "bank_data.txt";

public:
    Account* findAccount(std::string id);
    void createAccount(std::string accNum, std::string name, double bal, int type);
    bool transfer(std::string fromId, std::string toId, double amount);
    void showAllAccounts() const;
    void saveToDisk();
};

#endif