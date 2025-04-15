#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string accountHolder;
    double balance;

    static int totalAccounts; // Static variable to track total accounts

public:
    // Constructor to initialize account
    BankAccount(int accNum, string name, double initialBalance)
    {
        accountNumber = accNum;
        accountHolder = name;
        balance = initialBalance;
        totalAccounts++;
    }

    // Function to deposit amount
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposit successful.\n";
        }
        else
        {
            cout << "Invalid amount.\n";
        }
    }

    // Function to withdraw amount
    bool withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawal successful.\n";
            return true;
        }
        else
        {
            cout << "Insufficient funds or invalid amount.\n";
            return false;
        }
    }

    // Function to transfer funds to another account
    bool transfer(BankAccount &receiver, double amount)
    {
        if (withdraw(amount))
        {
            receiver.deposit(amount);
            cout << "Transfer successful.\n";
            return true;
        }
        return false;
    }

    // Function to display account info
    void display() const
    {
        cout << "Account Number: " << accountNumber
             << " | Name: " << accountHolder
             << " | Balance: $" << balance << endl;
    }

    // Accessors
    int getAccountNumber() const { return accountNumber; }

    static int getTotalAccounts() { return totalAccounts; }
};

// Static member initialization
int BankAccount::totalAccounts = 0;

// Function to find account by number
BankAccount *findAccount(vector<BankAccount> &accounts, int accNum)
{
    for (auto &acc : accounts)
    {
        if (acc.getAccountNumber() == accNum)
            return &acc;
    }
    return nullptr;
}

int main()
{
    vector<BankAccount> accounts;
    int choice;

    do
    {
        cout << "\n--- Community Bank Menu ---\n";
        cout << "1. Create New Account\n";
        cout << "2. Display All Accounts\n";
        cout << "3. Transfer Money\n";
        cout << "4. View Total Number of Accounts\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int accNum;
            string name;
            double initialBalance;

            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Account Holder's Name (one word): ";
            cin >> name; // Assumes no spaces in name
            cout << "Enter Initial Balance: $";
            cin >> initialBalance;

            accounts.emplace_back(accNum, name, initialBalance);
            cout << "Account created successfully.\n";
            break;
        }

        case 2:
        {
            cout << "\n--- All Accounts ---\n";
            for (const auto &acc : accounts)
            {
                acc.display();
            }
            break;
        }

        case 3:
        {
            int fromAcc, toAcc;
            double amount;

            cout << "Enter Sender Account Number: ";
            cin >> fromAcc;
            cout << "Enter Receiver Account Number: ";
            cin >> toAcc;
            cout << "Enter Amount to Transfer: $";
            cin >> amount;

            BankAccount *sender = findAccount(accounts, fromAcc);
            BankAccount *receiver = findAccount(accounts, toAcc);

            if (sender && receiver)
            {
                sender->transfer(*receiver, amount);
            }
            else
            {
                cout << "One or both accounts not found.\n";
            }
            break;
        }

        case 4:
            cout << "Total accounts created: " << BankAccount::getTotalAccounts() << endl;
            break;

        case 5:
            cout << "Thank you for using Community Bank System.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);
    cout << endl
         << endl
         << "This program is created by 24CE141 _ JENIL VIRADIA.";
    return 0;
}
