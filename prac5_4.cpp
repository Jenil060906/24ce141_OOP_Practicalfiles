#include <iostream>
#include <queue>
using namespace std;
class Fahrenheit;
class Celsius
{
    float c;

public:
    Celsius(float c = 0) : c(c) {}
    float getValue() const { return c; }

    operator Fahrenheit();
    bool operator==(const Celsius &other) const
    {
        return c == other.c;
    }
};
class Fahrenheit
{
    float f;

public:
    Fahrenheit(float f = 0) : f(f) {}
    float getValue() const { return f; }
    operator Celsius()
    {
        return Celsius((f - 32) * 5 / 9);
    }
    bool operator==(const Fahrenheit &other) const
    {
        return f == other.f;
    }
};
Celsius::operator Fahrenheit()
{
    return Fahrenheit(c * 9 / 5 + 32);
}
int main()
{
    queue<Celsius> tempQueue;
    Celsius c1(37), c2(0);
    Fahrenheit f1 = c1;
    Celsius c3 = f1;
    cout << "Celsius to Fahrenheit: " << f1.getValue() << " F" << endl;
    cout << "Fahrenheit to Celsius: " << c3.getValue() << " C" << endl;
    tempQueue.push(c1);
    tempQueue.push(c2);
    while (!tempQueue.empty())
    {
        cout << "In queue: " << tempQueue.front().getValue() << " C" << endl;
        tempQueue.pop();
    }
    cout << endl
         << endl
         << "This program is created by 24CE141 _ JENIL VIRADIA.";
    return 0;
}
