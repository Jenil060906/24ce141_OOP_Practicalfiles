#include <iostream>
#include <string>
using namespace std;

class Students
{
     int Student_Roll_Number;
     string Student_Name;
     float marks[3];

public:
     Students()
     { // Default constructor
          Student_Roll_Number = 0;
          Student_Name = "";
          for (int i = 0; i < 3; i++)
               marks[i] = 0;
     }

     Students(int Roll_Number, string name, float m[3])
     { // Parameterized constructor
          Student_Roll_Number = Roll_Number;
          Student_Name = name;
          for (int i = 0; i < 3; i++)
          {
               marks[i] = m[i];
          }
     }

     double Calculate_Average_Marks()
     {
          return (marks[0] + marks[1] + marks[2]) / 3.0;
     }

     void Display_Data()
     {
          cout << "\nRoll number of the student: " << Student_Roll_Number;
          cout << "\nName of the student: " << Student_Name;
          cout << "\nMarks of subject 1: " << marks[0];
          cout << "\nMarks of subject 2: " << marks[1];
          cout << "\nMarks of subject 3: " << marks[2];
          cout << "\nAverage marks: " << Calculate_Average_Marks() << endl;
     }
};

int main()
{
     Students S[3];

     for (int i = 0; i < 3; i++)
     {
          int Roll_Number;
          string name;
          float m[3];

          cout << "\nEnter details of student " << i + 1 << ":";
          cout << "\nEnter Roll Number: ";
          cin >> Roll_Number;

          cout << "Enter Name: ";
          cin >> name;

          cout << "Enter marks of three subjects:\n";
          for (int j = 0; j < 3; j++)
          {
               cout << "Subject " << j + 1 << ": ";
               cin >> m[j];
          }

          S[i] = Students(Roll_Number, name, m);
     }

     // Display all students' data
     for (int i = 0; i < 3; i++)
     {
          cout << "\nStudent " << i + 1 << " details:";
          S[i].Display_Data();
     }
     cout << endl
          << endl
          << "This program is created by 24CE141 _ JENIL VIRADIA.";
     return 0;
}
