#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure for holding account details
struct Account {
    string accNumber;
    string holderName;
    double balance;
};

// Function to create a new account
void createAccount(vector<Account>& accounts) {
    Account newAccount;
    cout << "Enter account number: ";
    cin >> newAccount.accNumber;
    cout << "Enter account holder name: ";
    cin >> newAccount.holderName;
    newAccount.balance = 0;
    accounts.push_back(newAccount);
    cout << "Account created successfully!" << endl;
}

// Function to deposit money into an account
void deposit(vector<Account>& accounts, const string& accNumber, double amount) {
    for (auto& acc : accounts) {
        if (acc.accNumber == accNumber) {
            acc.balance += amount;
            cout << "Deposit successful. New balance: " << acc.balance << endl;
            return;
        }
    }
    cout << "Account not found." << endl;
}

// Function to withdraw money from an account
void withdraw(vector<Account>& accounts, const string& accNumber, double amount) {
    for (auto& acc : accounts) {
        if (acc.accNumber == accNumber) {
            if (acc.balance >= amount) {
                acc.balance -= amount;
                cout << "Withdrawal successful. New balance: " << acc.balance << endl;
            } else {
                cout << "Insufficient balance." << endl;
            }
            return;
        }
    }
    cout << "Account not found." << endl;
}

// Function to close an account
void closeAccount(vector<Account>& accounts, const string& accNumber) {
    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if (it->accNumber == accNumber) {
            accounts.erase(it);
            cout << "Account closed successfully!" << endl;
            return;
        }
    }
    cout << "Account not found." << endl;
}

// Function to display account details
void displayAccount(const vector<Account>& accounts, const string& accNumber) {
    for (const auto& acc : accounts) {
        if (acc.accNumber == accNumber) {
            cout << "Account Number: " << acc.accNumber << endl;
            cout << "Holder Name: " << acc.holderName << endl;
            cout << "Balance: " << acc.balance << endl;
            return;
        }
    }
    cout << "Account not found." << endl;
}

int main() {
    vector<Account> accounts;
    int choice;
    string accNumber;
    double amount;

    while (true) {
        cout << "\nBank Management System\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Close Account\n";
        cout << "5. View Account Details\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount(accounts);
                break;
            case 2:
                cout << "Enter account number: ";
                cin >> accNumber;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                deposit(accounts, accNumber, amount);
                break;
            case 3:
                cout << "Enter account number: ";
                cin >> accNumber;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                withdraw(accounts, accNumber, amount);
                break;
            case 4:
                cout << "Enter account number to close: ";
                cin >> accNumber;
                closeAccount(accounts, accNumber);
                break;
            case 5:
                cout << "Enter account number to view details: ";
                cin >> accNumber;
                displayAccount(accounts, accNumber);
                break;
            case 6:
                cout << "Exiting...";
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
