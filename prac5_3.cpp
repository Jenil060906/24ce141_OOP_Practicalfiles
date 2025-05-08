#include <iostream>
#include <stack>
using namespace std;
class Point
{
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    Point operator-() const
    {
        return Point(-x, -y);
    }
    Point operator+(const Point &p) const
    {
        return Point(x + p.x, y + p.y);
    }
    bool operator==(const Point &p) const
    {
        return x == p.x && y == p.y;
    }
    void display() const
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};
int main()
{
    stack<Point> history;
    Point p1(3, 4), p2(-1, 2);
    Point sum = p1 + p2;
    Point neg = -p1;
    cout << "p1 + p2 = ";
    sum.display();
    cout << "-p1 = ";
    neg.display();
    cout << "p1 == p2? " << (p1 == p2 ? "Yes" : "No") << endl;
    history.push(p1);
    history.push(p2);

    cout << "Undo last operation: ";
    history.top().display();
    history.pop();
    cout << endl
         << endl
         << "This program is created by 24CE141 _ JENIL VIRADIA.";
    return 0;
}
