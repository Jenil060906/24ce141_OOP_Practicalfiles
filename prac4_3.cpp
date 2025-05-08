#include <iostream>
#include <string>
#include <queue>
using namespace std;
class Fuel
{
protected:
    string fuelType;

public:
    Fuel(const string &type) : fuelType(type) {}
    void displayFuelType() const
    {
        cout << "Fuel Type: " << fuelType << endl;
    }
};
class Brand
{
protected:
    string brandName;

public:
    Brand(const string &name) : brandName(name) {}
    void displayBrandName() const
    {
        cout << "Brand: " << brandName << endl;
    }
};
class Car : public Fuel, public Brand
{
public:
    Car(const string &type, const string &name) : Fuel(type), Brand(name) {}
    void displayCarInfo() const
    {
        displayBrandName();
        displayFuelType();
        cout << "--------------------------" << endl;
    }
};
int main()
{
    queue<Car> serviceQueue;
    serviceQueue.push(Car("Petrol", "Toyota"));
    serviceQueue.push(Car("Diesel", "Ford"));
    serviceQueue.push(Car("Electric", "Tesla"));
    serviceQueue.push(Car("Hybrid", "Honda"));
    while (!serviceQueue.empty())
    {
        Car currentCar = serviceQueue.front();
        currentCar.displayCarInfo();
        serviceQueue.pop();
    }
    cout << endl
         << endl
         << "This program is created by 24CE141 _ JENIL VIRADIA.";
    return 0;
}
