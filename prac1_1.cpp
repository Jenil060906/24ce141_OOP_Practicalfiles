#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    // Method to set up account details
    void createAccount(string name, int accNum, double initialBalance)
    {
        accountHolder = name;
        accountNumber = accNum;
        balance = initialBalance;
    }

    // Method to deposit money
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited $" << amount << " successfully.\n";
        }
        else
        {
            cout << "Deposit amount must be greater than zero.\n";
        }
    }

    // Method to withdraw money
    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "Withdrawal amount must be greater than zero.\n";
        }
        else if (amount > balance)
        {
            cout << "Error: Insufficient funds.\n";
        }
        else
        {
            balance -= amount;
            cout << "Withdrew $" << amount << " successfully.\n";
        }
    }

    // Method to check account balance
    void checkBalance() const
    {
        cout << "\nAccount Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
    }
};

int main()
{
    BankAccount account;

    string name;
    int accNumber;
    double initialBalance;

    // Getting account details from user
    cout << "Enter account holder's name: ";
    getline(cin, name);

    cout << "Enter account number: ";
    cin >> accNumber;

    cout << "Enter initial balance: $";
    cin >> initialBalance;

    // Creating the account
    account.createAccount(name, accNumber, initialBalance);

    int choice;
    double amount;

    do
    {
        cout << "\n--- Bank Account Menu ---\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter amount to deposit: $";
            cin >> amount;
            account.deposit(amount);
            break;
        case 2:
            cout << "Enter amount to withdraw: $";
            cin >> amount;
            account.withdraw(amount);
            break;
        case 3:
            account.checkBalance();
            break;
        case 4:
            cout << "Thank you for using our banking system.\n";
            break;
        default:
            cout << "Invalid choice. Please select from 1 to 4.\n";
        }
    } while (choice != 4);
    cout << endl
         << endl
         << "This program is created by 24CE141 _ JENIL VIRADIA.";
    return 0;
}
