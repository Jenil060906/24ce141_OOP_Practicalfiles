#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class TextStats
{
    char **lines;
    int capacity;
    int lineCount;
    int wordCount;
    int charCount;
    void resize(int newCapacity)
    {
        char **newLines = new char *[newCapacity];
        for (int i = 0; i < lineCount; ++i)
            newLines[i] = lines[i];

        delete[] lines;
        lines = newLines;
        capacity = newCapacity;
    }
    int countWords(const char *line)
    {
        int count = 0;
        bool inWord = false;
        for (int i = 0; line[i] != '\0'; ++i)
        {
            if (isspace(line[i]))
            {
                if (inWord)
                {
                    count++;
                    inWord = false;
                }
            }
            else
                inWord = true;
        }
        if (inWord)
            count++;
        return count;
    }

public:
    TextStats()
    {
        capacity = 10;
        lineCount = 0;
        wordCount = 0;
        charCount = 0;
        lines = new char *[capacity];
    }
    ~TextStats()
    {
        for (int i = 0; i < lineCount; ++i)
            delete[] lines[i];
        delete[] lines;
    }
    void processFile(const char *filename)
    {
        ifstream inFile(filename);
        if (!inFile)
        {
            cerr << "Error: Could not open file \"" << filename << "\"." << endl;
            return;
        }
        char buffer[1024];
        while (inFile.getline(buffer, sizeof(buffer)))
        {
            int len = strlen(buffer);
            char *newLine = new char[len + 1];
            strcpy(newLine, buffer);
            if (lineCount == capacity)
                resize(capacity * 2);
            lines[lineCount++] = newLine;

            charCount += len;
            charCount++;

            wordCount += countWords(newLine);
        }
        inFile.close();
    }
    void printStats() const
    {
        cout << "Total Lines: " << lineCount << endl;
        cout << "Total Words: " << wordCount << endl;
        cout << "Total Characters (including newlines): " << charCount << endl;
    }
};
int main()
{
    const char *filename = "sample.txt";
    TextStats stats;
    stats.processFile(filename);
    stats.printStats();
    cout << endl
         << endl
         << "This program is created by 24CE141 _ JENIL VIRADIA.";
    return 0;
}
