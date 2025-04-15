#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SuperDigitCalculator
{
private:
    string n;
    int k;

    // Helper function to convert string to vector of digits
    vector<int> stringToDigits(const string &str)
    {
        vector<int> digits;
        for (char ch : str)
            digits.push_back(ch - '0');

        return digits;
    }

    // Recursive function to find the super digit of a vector of digits
    int superDigit(vector<int> digits)
    {
        if (digits.size() == 1)
            return digits[0]; // base case

        long long sum = 0;
        for (int d : digits)
            sum += d;

        return superDigit(stringToDigits(to_string(sum)));
    }

public:
    // Constructor to initialize values
    SuperDigitCalculator(const string &number, int times)
    {
        n = number;
        k = times;
    }

    // Function to calculate the final super digit
    int calculate()
    {
        vector<int> baseDigits = stringToDigits(n);
        int baseSuperDigit = superDigit(baseDigits);

        // Now apply k multiplier as described
        long long multiplied = 1LL * baseSuperDigit * k;
        return superDigit(stringToDigits(to_string(multiplied)));
    }
};

int main()
{
    string n;
    int k;

    cout << "Enter number n : ";
    cin >> n;

    cout << "Enter repetition count k: ";
    cin >> k;

    // Create an object using constructor
    SuperDigitCalculator calculator(n, k);

    // Calculate and display result
    int result = calculator.calculate();
    cout << "\nThe Super Digit is: " << result << endl;
    cout << endl
         << endl
         << "This program is created by 24CE141 _ JENIL VIRADIA.";
    return 0;
}