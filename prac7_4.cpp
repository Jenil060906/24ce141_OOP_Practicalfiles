#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
const int NAME_LENGTH = 50;
const int INITIAL_CAPACITY = 10;
const char *FILENAME = "students.txt";
ostream &tab(ostream &os)
{
    return os << setw(15) << left;
}
class Student
{
public:
    char name[NAME_LENGTH];
    int marks;
    char grade;
    Student()
    {
        strcpy(name, "");
        marks = 0;
        grade = 'F';
    }
    bool loadFromLine(const char *line)
    {
        char temp[100];
        strcpy(temp, line);
        char *token = strtok(temp, ",");
        if (!token)
            return false;
        strcpy(name, token);
        token = strtok(NULL, ",");
        if (!token)
            return false;
        marks = atoi(token);
        token = strtok(NULL, ",");
        if (!token)
            return false;
        grade = token[0];
        return true;
    }
    void display() const
    {
        cout << tab << name << tab << marks << tab << grade << endl;
    }
};
class StudentReport
{
private:
    Student *students;
    int count;
    int capacity;
    void resize()
    {
        int newCap = capacity * 2;
        Student *newArray = new Student[newCap];
        for (int i = 0; i < count; ++i)
            newArray[i] = students[i];
        delete[] students;
        students = newArray;
        capacity = newCap;
    }

public:
    StudentReport()
    {
        capacity = INITIAL_CAPACITY;
        count = 0;
        students = new Student[capacity];
    }
    ~StudentReport()
    {
        delete[] students;
    }
    bool loadFromFile()
    {
        ifstream inFile(FILENAME);
        if (!inFile)
        {
            cerr << "Error: Could not open file \"" << FILENAME << "\".\n";
            return false;
        }
        char line[100];
        count = 0;
        while (inFile.getline(line, sizeof(line)))
        {
            Student s;
            if (s.loadFromLine(line))
            {
                if (count == capacity)
                    resize();
                students[count++] = s;
            }
        }
        inFile.close();
        return true;
    }
    void displayReport() const
    {
        if (count == 0)
        {
            cout << "No student records to display.\n";
            return;
        }
        cout << "\n--- Student Performance Report ---\n";
        cout << tab << "Name" << tab << "Marks" << tab << "Grade" << endl;
        cout << setfill('-') << setw(45) << "-" << setfill(' ') << endl;
        for (int i = 0; i < count; ++i)
            students[i].display();
    }
};
int main()
{
    StudentReport report;
    if (report.loadFromFile())
        report.displayReport();
    else
        cout << "Failed to load student data.\n";
    cout << endl
         << endl
         << "This program is created by 24CE141 _ JENIL VIRADIA.";
    return 0;
}
