#include <iostream>
using namespace std;
class DynamicArray
{
private:
    int *data;
    int size;
    int capacity;
    void resize(int newCapacity)
    {
        int *newData = new int[newCapacity];
        for (int i = 0; i < size; ++i)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    DynamicArray(int initialCapacity = 4)
        : size(0), capacity(initialCapacity)
    {
        data = new int[capacity];
    }
    ~DynamicArray()
    {
        delete[] data;
    }
    void insert(int value)
    {
        if (size == capacity)
            resize(capacity * 2);
        data[size++] = value;
    }
    void removeAt(int index)
    {
        if (index < 0 || index >= size)
        {
            cerr << "Index out of range: " << index << endl;
            return;
        }
        for (int i = index; i < size - 1; ++i)
            data[i] = data[i + 1];
        --size;
        if (size > 0 && size <= capacity / 4)
            resize(capacity / 2);
    }
    int get(int index) const
    {
        if (index < 0 || index >= size)
        {
            cerr << "Index out of range: " << index << endl;
            return -1;
        }
        return data[index];
    }
    int getSize() const
    {
        return size;
    }
    void print() const
    {
        cout << "[ ";
        for (int i = 0; i < size; ++i)
            cout << data[i] << (i + 1 < size ? ", " : " ");
        cout << "]  (size=" << size << ", cap=" << capacity << ")\n";
    }
};
int main()
{
    DynamicArray arr;
    cout << "Inserting 1,2,3,4,5 into array...\n";
    for (int v = 1; v <= 5; ++v)
    {
        arr.insert(v);
        arr.print();
    }
    cout << "\nRemoving element at index 2:\n";
    arr.removeAt(2);
    arr.print();
    cout << "\nInserting 6,7,8,9 to trigger resize...\n";
    for (int v = 6; v <= 9; ++v)
    {
        arr.insert(v);
        arr.print();
    }
    cout << "\nRemoving indices 0,0,0 to trigger shrink...\n";
    arr.removeAt(0);
    arr.removeAt(0);
    arr.removeAt(0);
    arr.print();
    cout << endl
         << endl
         << "This program is created by 24CE141 _ JENIL VIRADIA.";
    return 0;
}
