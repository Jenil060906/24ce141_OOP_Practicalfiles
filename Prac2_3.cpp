#include <iostream>
#include <cstring>
using namespace std;
class Bank_Account
{
     string Account_Holder_Name;
     int Account_Number;
     double Account_Balance;

public:
     Bank_Account() : Account_Holder_Name(""), Account_Number(0), Account_Balance(0.0) {} // DEFAULT CONSTRUCTOR DECLARED.
     Bank_Account(string name, int number, double balance)                                // PARAMETERIZED DECLARED.
     {
          Account_Holder_Name = name;
          Account_Number = number;
          Account_Balance = balance;
     }
     void Deposit_Amount(double amount); // FUNCTION FOR DEPOSITING MONEY.
     void Withdraw_Money(double amount); // FUNCTION FOR WITHDRAWING MONEY.
     void Display_Data() const;          // FUNCTION FOR DISPLAYING DATA.
};
void Bank_Account::Deposit_Amount(double amount)
{
     if (amount > 0)
     {
          Account_Balance = Account_Balance + amount;
          cout << endl
               << "The amount Rs" << amount << " has been added successfully to your account and your balance is now : " << Account_Balance;
     }
     else
          cout << endl
               << "The amount should be greater than zero.";
}
void Bank_Account::Withdraw_Money(double amount)
{
     if (amount <= 0)
          cout << endl
               << "The amount should be greater than zero for the withdrawal process.";
     else if (amount > Account_Balance)
          cout << endl
               << "The balance is insufficient to withdraw the amount.";
     else
     {
          Account_Balance -= amount;
          cout << endl
               << "Rs" << amount << " has been withdrawed from the account and the balance is now : " << Account_Balance;
     }
}
void Bank_Account::Display_Data() const
{
     cout << endl
          << "=====THE ACCOUNT DETAILS ARE GIVEN BELOW=====";
     cout << endl
          << "The account holder's name is : " << Account_Holder_Name;
     cout << endl
          << "The account number is : " << Account_Number;
     cout << endl
          << "The total balance in the account is : Rs" << Account_Balance;
}
int main()
{
     Bank_Account b1;
     int number, choice;
     string name;
     double balance, amount;
     cout << endl
          << "Enter account holder's name : ";
     cin >> name;
     cout << endl
          << "Enter account number : ";
     cin >> number;
     cout << endl
          << "Enter account balance : Rs";
     cin >> balance;
     b1 = Bank_Account(name, number, balance);
     do
     {
          cout << endl
               << "===SELECT FROM THE BELOW ABOVE OPTIONS===";
          cout << endl
               << "1.Deposit Money";
          cout << endl
               << "2.Withdraw Money";
          cout << endl
               << "3.Display Data";
          cout << endl
               << "4.Exit";
          cout << endl
               << "Select from the above options (1 to 4) : ";
          cin >> choice;
          switch (choice)
          {
          case 1:
               cout << endl
                    << "Enter amount : Rs";
               cin >> amount;
               b1.Deposit_Amount(amount);
               break;
          case 2:
               cout << endl
                    << "Enter amount : Rs";
               cin >> amount;
               b1.Withdraw_Money(amount);
               break;
          case 3:
               b1.Display_Data();
               break;
          case 4:
               cout << endl
                    << "You are now exited from main screen!!!";
               break;
          default:
               cout << endl
                    << "YOU HAVE SELECTED INVALID CHOICE! TRY AGAIN";
          }
     } while (choice != 4);
     cout << endl
          << endl
          << "This program is created by 24CE141 _ JENIL VIRADIA.";
     return 0;
}