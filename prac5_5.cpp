#include <iostream>
#include <cmath>
using namespace std;
class Shape
{
public:
    virtual double Area() const = 0;
    virtual ~Shape()
    {
        cout << "Base Shape destroyed.\n";
    }
};
class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double Area() const override
    {
        return length * width;
    }

    ~Rectangle()
    {
        cout << "Rectangle destroyed.\n";
    }
};
class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double Area() const override
    {
        return M_PI * radius * radius;
    }

    ~Circle()
    {
        cout << "Circle destroyed.\n";
    }
};
class ShapeManager
{
private:
    Shape **shapes;
    int capacity;
    int count;
    void resize(int newCapacity)
    {
        Shape **newShapes = new Shape *[newCapacity];
        for (int i = 0; i < count; ++i)
            newShapes[i] = shapes[i];
        delete[] shapes;
        shapes = newShapes;
        capacity = newCapacity;
    }

public:
    ShapeManager(int initCap = 4) : capacity(initCap), count(0)
    {
        shapes = new Shape *[capacity];
    }
    void addShape(Shape *shape)
    {
        if (count == capacity)
            resize(capacity * 2);
        shapes[count++] = shape;
    }
    void showAllAreas() const
    {
        for (int i = 0; i < count; ++i)
            cout << "Shape " << i + 1 << " Area: " << shapes[i]->Area() << endl;
    }
    ~ShapeManager()
    {
        for (int i = 0; i < count; ++i)
            delete shapes[i];
        delete[] shapes;
        cout << "ShapeManager destroyed.\n";
    }
};
int main()
{
    ShapeManager manager;
    manager.addShape(new Rectangle(10.0, 5.0));
    manager.addShape(new Circle(7.0));
    manager.addShape(new Rectangle(3.0, 4.0));
    manager.addShape(new Circle(2.5));
    cout << "\nDisplaying area of all shapes:\n";
    manager.showAllAreas();
    cout << endl
         << endl
         << "This program is created by 24CE141 _ JENIL VIRADIA.";
    return 0;
}
