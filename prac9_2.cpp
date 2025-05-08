#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <fstream>
using namespace std;
struct Transaction
{
    string type;
    double amount;
    double balanceAfter;
};
class BankAccount
{
private:
    string accountHolder;
    double balance;
    vector<Transaction> transactionHistory;
    void logTransaction(const string &type, double amount, double balanceAfter)
    {
        Transaction txn = {type, amount, balanceAfter};
        transactionHistory.push_back(txn);
        ofstream logFile("transaction_log.txt", ios::app);
        if (logFile.is_open())
        {
            logFile << type << ": " << amount << " | Balance after: " << balanceAfter << endl;
            logFile.close();
        }
    }

public:
    BankAccount(const string &holder, double initialBalance)
        : accountHolder(holder), balance(initialBalance) {}
    void deposit(double amount)
    {
        if (amount <= 0)
            throw invalid_argument("Deposit amount must be greater than zero.");
        balance += amount;
        logTransaction("Deposit", amount, balance);
        cout << "Deposited " << amount << ". New balance: " << balance << endl;
    }
    void withdraw(double amount)
    {
        if (amount <= 0)
            throw invalid_argument("Withdrawal amount must be greater than zero.");
        if (amount > balance)
            throw runtime_error("Insufficient funds for this transaction.");
        balance -= amount;
        logTransaction("Withdraw", amount, balance);
        cout << "Withdrew " << amount << ". New balance: " << balance << endl;
    }
    void displayAccountDetails()
    {
        cout << "Account holder: " << accountHolder << endl;
        cout << "Current balance: " << balance << endl;
    }
    void viewTransactionHistory()
    {
        cout << "\nTransaction History for " << accountHolder << ":\n";
        for (const auto &txn : transactionHistory)
            cout << txn.type << ": " << txn.amount << " | Balance after: " << txn.balanceAfter << endl;
        cout << endl;
    }
};
double readValidatedInput(const string &prompt)
{
    double value;
    string input;
    while (true)
    {
        cout << prompt;
        getline(cin, input);
        stringstream ss(input);
        if (ss >> value && ss.eof())
            return value;
        else
            cout << "Invalid input. Please enter a numeric value.\n";
    }
}
int main()
{
    cout << "=== Welcome to the Bank Account System ===\n";
    string accountHolder;
    cout << "Enter account holder name: ";
    getline(cin, accountHolder);
    double initialBalance = readValidatedInput("Enter initial deposit for the account: ");
    BankAccount account(accountHolder, initialBalance);
    char choice;
    do
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Display Account Details\n";
        cout << "4. View Transaction History\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        try
        {
            switch (choice)
            {
            case '1':
            {
                double amount = readValidatedInput("Enter deposit amount: ");
                account.deposit(amount);
                break;
            }
            case '2':
            {
                double amount = readValidatedInput("Enter withdrawal amount: ");
                account.withdraw(amount);
                break;
            }
            case '3':
                account.displayAccountDetails();
                break;
            case '4':
                account.viewTransactionHistory();
                break;
            case '5':
                cout << "Exiting system...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
        catch (const exception &e)
        {
            cerr << "Error: " << e.what() << endl;
        }
    } while (choice != '5');
    cout << endl
         << endl
         << "This program is created by 24CE141 _ JENIL VIRADIA.";
    return 0;
}
