#include <iostream>
#include <vector>
using namespace std;

class ArraySum
{
private:
    vector<int> numbers;

public:
    // Constructor to take input dynamically
    ArraySum(int size)
    {
        numbers.resize(size);
        cout << "Enter " << size << " integer elements:\n";
        for (int i = 0; i < size; ++i)
        {
            cout << "Element " << i + 1 << ": ";
            cin >> numbers[i];
        }
    }

    // Recursive function to calculate sum
    int recursiveSum(int index)
    {
        if (index < 0)
            return 0;
        return numbers[index] + recursiveSum(index - 1);
    }

    // Iterative function to calculate sum
    int iterativeSum()
    {
        int total = 0;
        for (int num : numbers)
        {
            total += num;
        }
        return total;
    }

    // Accessor to get size of vector
    int size() const
    {
        return numbers.size();
    }
};

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    // Create object with constructor
    ArraySum arr(size);

    // Calculate sums
    int sum_recursive = arr.recursiveSum(arr.size() - 1);
    int sum_iterative = arr.iterativeSum();

    // Display results
    cout << "\nRecursive Sum: " << sum_recursive;
    cout << "\nIterative Sum: " << sum_iterative << endl;
    cout << endl
         << endl
         << "This program is created by 24CE141 _ JENIL VIRADIA.";
    return 0;
}
