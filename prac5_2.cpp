#include <iostream>
using namespace std;
class Complex
{
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    Complex operator+(const Complex &c) const
    {
        return Complex(real + c.real, imag + c.imag);
    }
    Complex operator-(const Complex &c) const
    {
        return Complex(real - c.real, imag - c.imag);
    }
    friend istream &operator>>(istream &in, Complex &c)
    {
        cout << "Enter real and imaginary parts: ";
        cin >> c.real >> c.imag;
        return in;
    }
    friend ostream &operator<<(ostream &out, const Complex &c)
    {
        cout << c.real << " + " << c.imag << "i";
        return out;
    }
};
int main()
{
    Complex c1, c2, sum, diff;
    cin >> c1 >> c2;
    sum = c1 + c2;
    diff = c1 - c2;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << endl
         << endl
         << "This program is created by 24CE141 _ JENIL VIRADIA.";
    return 0;
}
