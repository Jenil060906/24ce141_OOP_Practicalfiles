#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Shape
{
protected:
    double radius;

public:
    Shape(double r = 0.0) : radius(r) {}
    void setRadius(double r) { radius = r; }
    double getRadius() const { return radius; }
    virtual ~Shape() {}
};
class Circle : public Shape
{
public:
    Circle(double r = 0.0) : Shape(r) {}

    double calculateArea() const
    {
        return M_PI * radius * radius;
    }

    void display() const
    {
        cout << "Radius: " << radius << ", Area: " << calculateArea() << endl;
    }
};
void dynamicApproach()
{
    cout << "\nDynamic Approach:\n";
    vector<Circle> circles;
    int n;
    cout << "Enter number of circles: ";
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        double r;
        cout << "Enter radius for circle " << i + 1 << ": ";
        cin >> r;
        circles.emplace_back(r);
    }

    for (size_t i = 0; i < circles.size(); ++i)
    {
        cout << "Circle " << i + 1 << " - ";
        circles[i].display();
    }
}
void staticApproach()
{
    cout << "\nStatic Approach:\n";
    const int SIZE = 3;
    Circle circles[SIZE];
    for (int i = 0; i < SIZE; ++i)
    {
        double r;
        cout << "Enter radius for circle " << i + 1 << ": ";
        cin >> r;
        circles[i].setRadius(r);
    }
    for (int i = 0; i < SIZE; ++i)
    {
        cout << "Circle " << i + 1 << " - ";
        circles[i].display();
    }
}
int main()
{
    dynamicApproach();
    staticApproach();
    cout << endl
         << endl
         << "This program is created by 24CE141 _ JENIL VIRADIA.";
    return 0;
}