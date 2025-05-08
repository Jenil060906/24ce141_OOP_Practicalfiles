#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
using namespace std;
struct WordEntry
{
    char *word;
    int count;
};
class WordFrequency
{
private:
    WordEntry *entries;
    int size;
    int capacity;
    void resize()
    {
        int newCapacity = capacity * 2;
        WordEntry *newEntries = new WordEntry[newCapacity];
        for (int i = 0; i < size; ++i)
        {
            newEntries[i].word = entries[i].word;
            newEntries[i].count = entries[i].count;
        }
        delete[] entries;
        entries = newEntries;
        capacity = newCapacity;
    }
    char *toLower(const char *str)
    {
        int len = strlen(str);
        char *lower = new char[len + 1];
        for (int i = 0; i < len; ++i)
            lower[i] = tolower(str[i]);
        lower[len] = '\0';
        return lower;
    }
    int findWord(const char *word)
    {
        for (int i = 0; i < size; ++i)
        {
            if (strcmp(entries[i].word, word) == 0)
                return i;
        }
        return -1;
    }

public:
    WordFrequency(int initialCapacity = 10)
    {
        capacity = initialCapacity;
        size = 0;
        entries = new WordEntry[capacity];
    }
    ~WordFrequency()
    {
        for (int i = 0; i < size; ++i)
            delete[] entries[i].word;
        delete[] entries;
    }
    void addWord(const char *wordRaw)
    {
        char *word = toLower(wordRaw);
        int index = findWord(word);
        if (index != -1)
        {
            entries[index].count++;
            delete[] word;
        }
        else
        {
            if (size == capacity)
                resize();
            entries[size].word = word;
            entries[size].count = 1;
            size++;
        }
    }
    void writeToFile(const char *filename)
    {
        ofstream fout(filename);
        if (!fout)
        {
            cerr << "Error opening file for writing.\n";
            return;
        }
        for (int i = 0; i < size; ++i)
            fout << entries[i].word << ": " << entries[i].count << endl;
        fout.close();
    }
    void displayFromFile(const char *filename)
    {
        ifstream fin(filename);
        if (!fin)
        {
            cerr << "Error opening file for reading.\n";
            return;
        }
        cout << "\nWord Frequencies (from file):\n";
        string line;
        while (getline(fin, line))
            cout << line << endl;
        fin.close();
    }
};
void processParagraph(WordFrequency &wf, const char *paragraph)
{
    char buffer[100];
    int j = 0;
    for (int i = 0;; ++i)
    {
        char ch = paragraph[i];
        if (isalnum(ch))
        {
            buffer[j++] = ch;
        }
        else if (j > 0)
        {
            buffer[j] = '\0';
            wf.addWord(buffer);
            j = 0;
        }
        if (ch == '\0')
            break;
    }
}
int main()
{
    const int MAX = 1000;
    char paragraph[MAX];
    cout << "Enter a paragraph:\n";
    cin.getline(paragraph, MAX);
    WordFrequency wf;
    processParagraph(wf, paragraph);
    const char *filename = "output.txt";
    wf.writeToFile(filename);
    wf.displayFromFile(filename);
    cout << endl
         << endl
         << "This program is created by 24CE141 _ JENIL VIRADIA.";
    return 0;
}
