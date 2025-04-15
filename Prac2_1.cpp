#include <iostream>
using namespace std;
class Rectangle
{
    float length, breadth;

public:
    void Insert_Data()
    {
        cout << endl
             << "Enter length of rectangle : ";
        cin >> length;
        cout << endl
             << "Enter breadth of rectangle : ";
        cin >> breadth;
    }
    float Area_Of_Rectangle()
    {
        return length * breadth;
    }
    float Perimeter_Of_Rectangle()
    {
        return 2 * (length + breadth);
    }
};
int main()
{
    Rectangle R[100];
    int Number_Of_Rectangles;
    cout << endl
         << "Enter number of rectangles : ";
    cin >> Number_Of_Rectangles;
    for (int i = 0; i < Number_Of_Rectangles; i++)
    {
        cout << endl
             << endl
             << "==========Enter details of rectangle " << i + 1 << " ========== " << endl;
        R[i].Insert_Data();
        float Area = R[i].Area_Of_Rectangle();
        cout << endl
             << "The area of rectangle " << i + 1 << " is : " << Area;
        float Perimeter = R[i].Perimeter_Of_Rectangle();
        cout << endl
             << "The perimeter of rectangle " << i + 1 << " is : " << Perimeter;
    }
    cout << endl
         << endl
         << "This program is created by 24CE141 _ JENIL VIRADIA.";
    return 0;
}