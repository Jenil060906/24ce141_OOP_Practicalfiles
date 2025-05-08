#include <iostream>
using namespace std;
class Point
{
private:
    float x;
    float y;

public:
    Point(float xVal = 0, float yVal = 0) : x(xVal), y(yVal) {}
    Point *moveBy(float dx, float dy)
    {
        x += dx;
        y += dy;
        return this;
    }
    Point *scale(float factor)
    {
        x *= factor;
        y *= factor;
        return this;
    }
    void display() const
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};
void transformPoint(Point *p)
{
    p->moveBy(5, -3)->scale(2)->moveBy(-1, 4);
}

int main()
{
    Point *p = new Point(2.0f, 3.0f);
    cout << "Initial Point: ";
    p->display();
    transformPoint(p);
    cout << "Transformed Point: ";
    p->display();
    delete p;
    cout << endl
         << endl
         << "This program is created by 24CE141 _ JENIL VIRADIA.";
    return 0;
}
