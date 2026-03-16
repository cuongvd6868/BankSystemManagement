#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

class Account {
protected:
    std::string accountNumber;
    std::string ownerName;
    double balance;

public:
    Account(std::string accNum, std::string name, double initialBalance);
    virtual ~Account();

    virtual bool withdraw(double amount) = 0; 
    void deposit(double amount);
    virtual void displayInfo() const;

    std::string getAccNum() const;
    double getBalance() const;
};
#endif