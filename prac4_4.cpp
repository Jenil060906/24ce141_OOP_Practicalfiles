#include <iostream>
#include <stack>
using namespace std;
class Bank_Account
{
protected:
    string Acc_Num;
    double balance;

public:
    Bank_Account(string acc, double bal) : Acc_Num(acc), balance(bal) {}

    virtual void deposit(double amount)
    {
        balance += amount;
        cout << "\nDeposited: " << amount << ", Balance: " << balance << endl;
    }

    virtual int withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "\nWithdrawn: " << amount << ", Balance: " << balance << endl;
            return 1;
        }
        else
        {
            cout << "\nInsufficient balance!" << endl;
            return 0;
        }
    }

    double Get_Balance() const
    {
        return balance;
    }

    virtual ~Bank_Account() {}
};
class Saving_Account : public Bank_Account
{
public:
    Saving_Account(string acc, double bal) : Bank_Account(acc, bal) {}
};
class Current_Account : public Bank_Account
{
    double Overdraft_Limit;

public:
    Current_Account(string acc, double bal, double limit)
        : Bank_Account(acc, bal), Overdraft_Limit(limit) {}

    int withdraw(double amount) override
    {
        if (balance + Overdraft_Limit >= amount)
        {
            balance -= amount;
            cout << "\nWithdrawn: " << amount << ", Balance: " << balance << endl;
            return 1;
        }
        else
        {
            cout << "\nOverdraft limit exceeded!" << endl;
            return 0;
        }
    }

    double Get_Overdraft_Limit() const
    {
        return Overdraft_Limit;
    }
};
struct transaction
{
    string type;
    double amount;
};
void Show_Menu()
{
    cout << "\n1. Deposit\n2. Withdraw\n3. Undo\n4. Show balance\n0. Exit\n\nEnter choice: ";
}
int main()
{
    string type, AccNum;
    double bal;
    cout << "\nAccount type (savings/current): ";
    cin >> type;
    cout << "Account number: ";
    cin >> AccNum;
    cout << "Initial balance: ";
    cin >> bal;
    stack<transaction> history;
    int ch;
    double amt;
    if (type == "savings")
    {
        Saving_Account acc(AccNum, bal);
        do
        {
            Show_Menu();
            cin >> ch;
            switch (ch)
            {
            case 1:
                cout << "Amount: ";
                cin >> amt;
                acc.deposit(amt);
                history.push({"deposit", amt});
                break;
            case 2:
                cout << "Amount: ";
                cin >> amt;
                if (acc.withdraw(amt))
                    history.push({"withdraw", amt});
                break;
            case 3:
                if (!history.empty())
                {
                    transaction last = history.top();
                    history.pop();
                    if (last.type == "deposit")
                    {
                        acc.withdraw(last.amount);
                        cout << "\nUndoing deposit of " << last.amount << endl;
                    }
                    else if (last.type == "withdraw")
                    {
                        acc.deposit(last.amount);
                        cout << "\nUndoing withdrawal of " << last.amount << endl;
                    }
                }
                else
                    cout << "\nNo transaction to undo." << endl;
                break;
            case 4:
                cout << "\nBalance: " << acc.Get_Balance() << endl;
                break;
            }
        } while (ch != 0);
    }
    else if (type == "current")
    {
        double limit;
        cout << "Enter overdraft limit: ";
        cin >> limit;
        Current_Account acc(AccNum, bal, limit);
        do
        {
            Show_Menu();
            cin >> ch;
            switch (ch)
            {
            case 1:
                cout << "Amount: ";
                cin >> amt;
                acc.deposit(amt);
                history.push({"deposit", amt});
                break;
            case 2:
                cout << "Amount: ";
                cin >> amt;
                if (acc.withdraw(amt))
                    history.push({"withdraw", amt});
                break;
            case 3:
                if (!history.empty())
                {
                    transaction last = history.top();
                    history.pop();
                    if (last.type == "deposit")
                    {
                        acc.withdraw(last.amount);
                        cout << "\nUndoing deposit of " << last.amount << endl;
                    }
                    else if (last.type == "withdraw")
                    {
                        acc.deposit(last.amount);
                        cout << "\nUndoing withdrawal of " << last.amount << endl;
                    }
                }
                else
                    cout << "\nNo transaction to undo." << endl;
                break;
            case 4:
                cout << "\nBalance: " << acc.Get_Balance() << endl;
                break;
            }
        } while (ch != 0);
    }
    else
        cout << "\nInvalid account type." << endl;
    cout << "\n\nThis program is created by 24CE141 _ JENIL VIRADIA.\n";
    return 0;
}
