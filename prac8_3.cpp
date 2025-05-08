#include <iostream>
#include <set>
#include <vector>
using namespace std;
class TransactionFilter
{
private:
    set<int> uniqueTransactions;

public:
    void addTransactions(const vector<int> &transactions)
    {
        for (int id : transactions)
            uniqueTransactions.insert(id);
    }
    void displayUniqueTransactions() const
    {
        cout << "\nUnique Sorted Transaction IDs:\n";
        for (auto it = uniqueTransactions.begin(); it != uniqueTransactions.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    vector<int> getUniqueTransactions() const
    {
        return vector<int>(uniqueTransactions.begin(), uniqueTransactions.end());
    }
};
int main()
{
    TransactionFilter filter;
    int n, value;
    vector<int> inputTransactions;
    cout << "Enter number of transaction IDs: ";
    cin >> n;
    cout << "Enter transaction IDs:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> value;
        inputTransactions.push_back(value);
    }
    filter.addTransactions(inputTransactions);
    filter.displayUniqueTransactions();
    return 0;
}
