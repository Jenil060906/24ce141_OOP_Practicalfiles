#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <cctype>
using namespace std;
class WordFrequencyAnalyzer
{
    map<string, int> wordFreq;
    string toLower(const string &word)
    {
        string result;
        for (char ch : word)
            result += tolower(ch);
        return result;
    }
    string removePunctuation(const string &word)
    {
        string result;
        for (char ch : word)
        {
            if (isalnum(ch))
                result += ch;
        }
        return result;
    }

public:
    void processText(const string &text)
    {
        stringstream ss(text);
        string word;
        while (ss >> word)
        {
            word = removePunctuation(toLower(word));
            if (!word.empty())
                wordFreq[word]++;
        }
    }
    void displayFrequencies() const
    {
        cout << "\nWord Frequency Distribution:\n";
        for (auto it = wordFreq.begin(); it != wordFreq.end(); ++it)
            cout << it->first << " : " << it->second << endl;
    }
};
int main()
{
    WordFrequencyAnalyzer analyzer;
    string inputText;
    cout << "Enter a sentence:\n";
    getline(cin, inputText);
    analyzer.processText(inputText);
    analyzer.displayFrequencies();
    cout << endl
         << endl
         << "This program is created by 24CE141 _ JENIL VIRADIA.";
    return 0;
}
