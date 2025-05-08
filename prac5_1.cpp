#include <iostream>
using namespace std;
class Calculator
{
public:
    int add(int a, int b)
    {
        return a + b;
    }

    float add(float a, float b)
    {
        return a + b;
    }

    double add(double a, double b)
    {
        return a + b;
    }

    int add(int a, int b, int c)
    {
        return a + b + c;
    }
};
int main()
{
    Calculator calc;
    cout << "Integer addition: " << calc.add(2, 3) << endl;
    cout << "Float addition: " << calc.add(2.5f, 3.5f) << endl;
    cout << "Double addition: " << calc.add(3.14, 2.71) << endl;
    cout << "Three integer addition: " << calc.add(1, 2, 3) << endl;
    cout << endl
         << endl
         << "This program is created by 24CE141 _ JENIL VIRADIA.";
    return 0;
}
