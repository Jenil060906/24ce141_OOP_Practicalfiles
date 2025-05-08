#include <iostream>
using namespace std;
class SortedDataset
{
private:
    int *data;
    int size;

public:
    SortedDataset(int s = 0) : size(s)
    {
        if (size > 0)
            data = new int[size];
        else
            data = nullptr;
    }
    ~SortedDataset()
    {
        delete[] data;
    }
    void inputData()
    {
        cout << "Enter " << size << " sorted elements:\n";
        for (int i = 0; i < size; ++i)
        {
            cin >> data[i];
        }
    }
    void display() const
    {
        for (int i = 0; i < size; ++i)
            cout << data[i] << " ";
        cout << endl;
    }
    int *getData() const { return data; }
    int getSize() const { return size; }
    static SortedDataset merge(const SortedDataset &d1, const SortedDataset &d2)
    {
        int newSize = d1.size + d2.size;
        SortedDataset merged(newSize);
        int *a = d1.data;
        int *b = d2.data;
        int *m = merged.data;
        int i = 0, j = 0, k = 0;
        while (i < d1.size && j < d2.size)
        {
            if (a[i] <= b[j])
                m[k++] = a[i++];
            else
                m[k++] = b[j++];
        }
        while (i < d1.size)
            m[k++] = a[i++];
        while (j < d2.size)
            m[k++] = b[j++];
        return merged;
    }
};
int main()
{
    int size1, size2;
    cout << "Enter size of first sorted dataset: ";
    cin >> size1;
    SortedDataset dataset1(size1);
    dataset1.inputData();
    cout << "Enter size of second sorted dataset: ";
    cin >> size2;
    SortedDataset dataset2(size2);
    dataset2.inputData();
    cout << "\nMerging datasets...\n";
    SortedDataset merged = SortedDataset::merge(dataset1, dataset2);
    cout << "Merged Sorted Dataset:\n";
    merged.display();
    cout << endl
         << endl
         << "This program is created by 24CE141 _ JENIL VIRADIA.";
    return 0;
}
