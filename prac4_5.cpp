#include <iostream>
#include <vector>
#include <memory>
using namespace std;
class Student
{
protected:
    string name;
    int marks;

public:
    Student(const string &name, int marks) : name(name), marks(marks) {}
    virtual void computeGrade() const = 0;
    virtual void display() const
    {
        cout << "Name: " << name << "\nMarks: " << marks << endl;
    }
    virtual ~Student() {}
};
class Undergraduate : public Student
{
public:
    Undergraduate(const string &name, int marks) : Student(name, marks) {}

    void computeGrade() const override
    {
        display();
        if (marks >= 70)
            cout << "Grade: A\n";
        else if (marks >= 50)
            cout << "Grade: B\n";
        else
            cout << "Grade: C\n";
        cout << "-----------------------\n";
    }
};
class Postgraduate : public Student
{
public:
    Postgraduate(const string &name, int marks) : Student(name, marks) {}

    void computeGrade() const override
    {
        display();
        if (marks >= 80)
            cout << "Grade: A\n";
        else if (marks >= 60)
            cout << "Grade: B\n";
        else
            cout << "Grade: C\n";
        cout << "-----------------------\n";
    }
};
int main()
{
    vector<shared_ptr<Student>> students;
    int choice, marks;
    string name;
    cout << "Enter number of students: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cout << "\nEnter student name: ";
        cin >> ws;
        getline(cin, name);
        cout << "Enter marks: ";
        cin >> marks;
        cout << "1. Undergraduate\n2. Postgraduate\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
            students.push_back(make_shared<Undergraduate>(name, marks));
        else if (choice == 2)
            students.push_back(make_shared<Postgraduate>(name, marks));
        else
            cout << "Invalid choice. Skipping student.\n";
    }
    cout << "\n--- Grade Report ---\n";
    for (const auto &student : students)
        student->computeGrade();
    cout << endl
         << endl
         << "This program is created by 24CE141 _ JENIL VIRADIA.";
    return 0;
}