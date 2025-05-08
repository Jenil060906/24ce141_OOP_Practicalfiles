#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
ostream &currency(ostream &os)
{
    return os << "₹";
}
class Student
{
    char name[50];
    float marks;
    float tuitionFee;

public:
    Student()
    {
        strcpy(name, "");
        marks = 0.0;
        tuitionFee = 0.0;
    }
    bool loadFromLine(const char *line)
    {
        char temp[100];
        strcpy(temp, line);
        char *token = strtok(temp, ",");
        if (!token)
            return false;
        strcpy(name, token);
        token = strtok(nullptr, ",");
        if (!token)
            return false;
        marks = atof(token);
        token = strtok(nullptr, ",");
        if (!token)
            return false;
        tuitionFee = atof(token);
        return true;
    }
    void display() const
    {
        cout << left << setw(20) << name
             << right << setw(10) << fixed << setprecision(2) << marks
             << right << setw(15) << currency << fixed << setprecision(2) << tuitionFee
             << endl;
    }
};
class StudentReport
{
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
    StudentReport(int initCap = 10)
    {
        capacity = initCap;
        count = 0;
        students = new Student[capacity];
    }
    ~StudentReport()
    {
        delete[] students;
    }
    bool loadFromFile(const char *filename)
    {
        ifstream inFile(filename);
        if (!inFile)
        {
            cerr << "Error: Could not open file \"" << filename << "\".\n";
            return false;
        }
        char line[100];
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
        cout << left << setw(20) << "Name"
             << right << setw(10) << "Marks"
             << right << setw(15) << "Tuition Fee" << endl;
        cout << setfill('-') << setw(45) << "-" << setfill(' ') << endl;
        for (int i = 0; i < count; ++i)
            students[i].display();
    }
};
int main()
{
    const char *filename = "students_fees.txt";
    StudentReport report;

    if (report.loadFromFile(filename))
    {
        cout << "\n--- University Student Report ---\n";
        report.displayReport();
    }
    else
        cout << "Failed to load student records.\n";
    cout << endl
         << endl
         << "This program is created by 24CE141 _ JENIL VIRADIA.";
    return 0;
}
