#include <iostream>
#include "Bank.h"

using namespace std;

void showMenu() {
    cout << "\n========== BANK MANAGEMENT SYSTEM ==========\n";
    cout << "1. Open New Account\n";
    cout << "2. Transfer Money\n";
    cout << "3. Deposit Money\n";
    cout << "4. Show All Accounts (Admin)\n";
    cout << "5. Sync to Database (File)\n";
    cout << "0. Exit\n";
    cout << "--------------------------------------------\n";
    cout << "Your choice: ";
}

int main() {
    Bank myBank;
    int choice;
    string id1, id2, name;
    double amount;
    int type;

    while (true) {
        showMenu();
        if (!(cin >> choice)) break;

        switch (choice) {
            case 1:
                cout << "Type (1: Savings, 2: Checking): "; cin >> type;
                cout << "Account Number: "; cin >> id1;
                cout << "Owner Name: "; cin.ignore(); getline(cin, name);
                cout << "Initial Balance: "; cin >> amount;
                myBank.createAccount(id1, name, amount, type);
                cout << "=> Account created successfully!\n";
                break;

            case 2:
                cout << "From Account ID: "; cin >> id1;
                cout << "To Account ID: "; cin >> id2;
                cout << "Amount: "; cin >> amount;
                if (myBank.transfer(id1, id2, amount)) 
                    cout << "=> Transfer successful!\n";
                else 
                    cout << "=> Transfer failed! Check balance or IDs.\n";
                break;

            case 3:
                cout << "Account ID: "; cin >> id1;
                cout << "Deposit Amount: "; cin >> amount;
                if (Account* acc = myBank.findAccount(id1)) {
                    acc->deposit(amount);
                    cout << "=> Deposit successful!\n";
                } else cout << "=> Account not found!\n";
                break;

            case 4:
                myBank.showAllAccounts();
                break;

            case 5:
                myBank.saveToDisk();
                cout << "=> Data synchronized to bank_data.txt\n";
                break;

            case 0:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}