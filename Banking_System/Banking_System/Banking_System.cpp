#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Account {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    Account(string number, string name) : accountNumber(number), accountHolderName(name), balance(0.0) {}

    
    string getAccountNumber() const {
        return accountNumber;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        }
        else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
        else {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    void displayAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

class BankingSystem {
private:
    vector<Account> accounts;

public:
    void createAccount() {
        string number, name;
        cout << "Enter account number: ";
        cin >> number;
        cout << "Enter account holder name: ";
        cin.ignore();
        getline(cin, name);

        Account newAccount(number, name);
        accounts.push_back(newAccount);
        cout << "Account created successfully!" << endl;
    }

    Account* findAccount(const string& accountNumber) {
        for (auto& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                return &account;
            }
        }
        return nullptr;
    }

    void deposit() {
        string number;
        double amount;
        cout << "Enter account number: ";
        cin >> number;
        cout << "Enter deposit amount: ";
        cin >> amount;

        Account* account = findAccount(number);
        if (account) {
            account->deposit(amount);
        }
        else {
            cout << "Account not found!" << endl;
        }
    }

    void withdraw() {
        string number;
        double amount;
        cout << "Enter account number: ";
        cin >> number;
        cout << "Enter withdrawal amount: ";
        cin >> amount;

        Account* account = findAccount(number);
        if (account) {
            account->withdraw(amount);
        }
        else {
            cout << "Account not found!" << endl;
        }
    }

    void displayBalance() {
        string number;
        cout << "Enter account number: ";
        cin >> number;

        Account* account = findAccount(number);
        if (account) {
            account->displayAccountInfo();
        }
        else {
            cout << "Account not found!" << endl;
        }
    }
};

int main() {
    BankingSystem bankingSystem;
    char choice;

    do {
        cout << "\nBanking System Menu:" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case '1':
            bankingSystem.createAccount();
            break;
        case '2':
            bankingSystem.deposit();
            break;
        case '3':
            bankingSystem.withdraw();
            break;
        case '4':
            bankingSystem.displayBalance();
            break;
        case '5':
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != '5');

    return 0;
}
