#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class SequenceProcessor
{
    vector<int> sequence;

public:
    void readInput()
    {
        int n, value;
        cout << "Enter the number of elements: ";
        cin >> n;
        cout << "Enter " << n << " integers:\n";
        for (int i = 0; i < n; ++i)
        {
            cin >> value;
            sequence.push_back(value);
        }
    }
    void reverseWithStd()
    {
        vector<int> reversed = sequence;
        std::reverse(reversed.begin(), reversed.end());
        cout << "\nReversed using std::reverse(): ";
        displaySequence(reversed);
    }
    void reverseWithIterators()
    {
        vector<int> reversed;
        for (auto it = sequence.rbegin(); it != sequence.rend(); ++it)
            reversed.push_back(*it);
        cout << "Reversed using manual iterators: ";
        displaySequence(reversed);
    }

private:
    void displaySequence(const vector<int> &seq) const
    {
        for (auto num : seq)
            cout << num << " ";
        cout << endl;
    }
};
int main()
{
    SequenceProcessor processor;
    processor.readInput();
    processor.reverseWithStd();
    processor.reverseWithIterators();
    cout << endl
         << endl
         << "This program is created by 24CE141 _ JENIL VIRADIA.";
    return 0;
}
