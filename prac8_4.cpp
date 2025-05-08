#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
struct Student
{
    string name;
    int score;
};
bool compareByScore(const Student &a, const Student &b)
{
    return a.score > b.score;
}
class StudentRankingSystem
{
    vector<Student> students;

public:
    void addStudent(const string &name, int score)
    {
        students.push_back({name, score});
    }
    void sortStudents()
    {
        sort(students.begin(), students.end(), compareByScore);
    }
    void displayRankings() const
    {
        cout << "\nRanked List of Students:\n";
        cout << left << setw(6) << "Rank" << setw(15) << "Name" << "Score\n";
        cout << "------------------------------\n";
        int rank = 1;
        for (auto it = students.begin(); it != students.end(); ++it)
            cout << left << setw(6) << rank++ << setw(15) << it->name << it->score << "\n";
    }
};
int main()
{
    StudentRankingSystem rankingSystem;
    int n;
    string name;
    int score;
    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter name of student " << i + 1 << ": ";
        getline(cin, name);
        cout << "Enter score for " << name << ": ";
        cin >> score;
        cin.ignore();
        rankingSystem.addStudent(name, score);
    }
    rankingSystem.sortStudents();
    rankingSystem.displayRankings();
    cout << endl
         << endl
         << "This program is created by 24CE141 _ JENIL VIRADIA.";
    return 0;
}
