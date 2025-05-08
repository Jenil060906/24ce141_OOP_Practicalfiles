#include <iostream>
#include <string>
#include <map>
using namespace std;
class Person
{
protected:
    string name;
    int age;

public:
    Person(string n = "", int a = 0) : name(n), age(a) {}
    virtual void display() const
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};
class Employee : public Person
{
protected:
    int employeeID;

public:
    Employee(string n = "", int a = 0, int id = 0) : Person(n, a), employeeID(id) {}
    void display() const override
    {
        Person::display();
        cout << "Employee ID: " << employeeID << endl;
    }
    int getID() const { return employeeID; }
};
class Manager : public Employee
{
    string department;

public:
    Manager(string n = "", int a = 0, int id = 0, string dept = "")
        : Employee(n, a, id), department(dept) {}

    void display() const override
    {
        Employee::display();
        cout << "Department: " << department << endl;
    }
};
void dynamicApproach()
{
    cout << "\nDynamic Approach (map):\n";
    map<int, Manager> managerMap;
    int n;
    cout << "Enter number of managers: ";
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string name, department;
        int age, id;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter employee ID: ";
        cin >> id;
        cout << "Enter department: ";
        cin.ignore();
        getline(cin, department);
        managerMap[id] = Manager(name, age, id, department);
    }
    for (const auto &entry : managerMap)
    {
        cout << "\nManager with ID " << entry.first << ":\n";
        entry.second.display();
    }
}
void staticApproach()
{
    cout << "\nStatic Approach (array):\n";
    const int SIZE = 2;
    Manager managers[SIZE];
    for (int i = 0; i < SIZE; ++i)
    {
        string name, department;
        int age, id;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter employee ID: ";
        cin >> id;
        cout << "Enter department: ";
        cin.ignore();
        getline(cin, department);
        managers[i] = Manager(name, age, id, department);
    }
    for (int i = 0; i < SIZE; ++i)
    {
        cout << "\nManager " << i + 1 << ":\n";
        managers[i].display();
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