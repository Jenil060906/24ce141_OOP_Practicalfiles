#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iomanip>
using namespace std;
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
void calculateRatio()
{
    try
    {
        double loanAmount = readValidatedInput("Enter loan amount: ");
        double income = readValidatedInput("Enter annual income: ");
        if (income == 0)
            throw runtime_error("Annual income cannot be zero. Division by zero is not allowed.");
        double ratio = loanAmount / income;
        cout << fixed << setprecision(2);
        cout << "Loan-to-Income Ratio: " << ratio << endl;
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
}
int main()
{
    cout << "=== Financial Calculator: Loan-to-Income Ratio ===\n";
    char choice;
    do
    {
        calculateRatio();
        cout << "\nWould you like to perform another calculation? (y/n): ";
        cin >> choice;
        cin.ignore();
    } while (tolower(choice) == 'y');
    cout << "Thank you for using the financial calculator.\n";
    cout << endl
         << endl
         << "This program is created by 24CE141 _ JENIL VIRADIA.";
    return 0;
}
