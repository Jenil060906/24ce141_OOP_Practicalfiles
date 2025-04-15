#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Template class to handle collections of any data type
template <typename T>
class Collection
{
private:
    vector<T> elements;

public:
    // Constructor to initialize collection with user input
    Collection(int size)
    {
        T value;
        cout << "Enter " << size << " elements:\n";
        for (int i = 0; i < size; ++i)
        {
            cout << "Element " << i + 1 << ": ";
            cin >> value;
            elements.push_back(value);
        }
    }

    // Display all elements
    void display() const
    {
        cout << "Collection elements: ";
        for (const T &val : elements)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    // Find the maximum element
    T findMax() const
    {
        T maxVal = elements[0];
        for (const T &val : elements)
        {
            if (val > maxVal)
                maxVal = val;
        }
        return maxVal;
    }

    // Reverse the collection
    void reverse()
    {
        std::reverse(elements.begin(), elements.end());
        cout << "Collection reversed.\n";
    }
};

// Menu to test the template with multiple types
int main()
{
    int choice;

    do
    {
        cout << "\n--- Generic Collection Manager ---\n";
        cout << "1. Integer Collection\n";
        cout << "2. Float Collection\n";
        cout << "3. Character Collection\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        int size;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter number of elements: ";
            cin >> size;
            Collection<int> intColl(size);
            intColl.display();
            cout << "Max element: " << intColl.findMax() << endl;
            intColl.reverse();
            intColl.display();
            break;
        }

        case 2:
        {
            cout << "Enter number of elements: ";
            cin >> size;
            Collection<float> floatColl(size);
            floatColl.display();
            cout << "Max element: " << floatColl.findMax() << endl;
            floatColl.reverse();
            floatColl.display();
            break;
        }

        case 3:
        {
            cout << "Enter number of elements: ";
            cin >> size;
            Collection<char> charColl(size);
            charColl.display();
            cout << "Max element: " << charColl.findMax() << endl;
            charColl.reverse();
            charColl.display();
            break;
        }

        case 4:
            cout << "Exiting program. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);
    cout << endl
         << endl
         << "This program is created by 24CE141 _ JENIL VIRADIA.";
    return 0;
}