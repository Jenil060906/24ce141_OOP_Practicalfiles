#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class DirectoryManager
{
    map<string, vector<string>> directory;

public:
    void addFolder(const string &folderName)
    {
        if (directory.find(folderName) == directory.end())
        {
            directory[folderName] = vector<string>();
            cout << "Folder '" << folderName << "' created.\n";
        }
        else
            cout << "Folder '" << folderName << "' already exists.\n";
    }
    void addFileToFolder(const string &folderName, const string &fileName)
    {
        auto it = directory.find(folderName);
        if (it != directory.end())
        {
            it->second.push_back(fileName);
            cout << "File '" << fileName << "' added to folder '" << folderName << "'.\n";
        }
        else
            cout << "Folder '" << folderName << "' does not exist.\n";
    }
    void displayDirectory() const
    {
        cout << "\n--- Directory Structure ---\n";
        for (auto folderIt = directory.begin(); folderIt != directory.end(); ++folderIt)
        {
            cout << folderIt->first << ":\n";
            const vector<string> &files = folderIt->second;
            for (auto fileIt = files.begin(); fileIt != files.end(); ++fileIt)
                cout << "  - " << *fileIt << '\n';
        }
    }
};
int main()
{
    DirectoryManager manager;
    int choice;
    string folder, file;
    while (true)
    {
        cout << "\n1. Add Folder\n2. Add File to Folder\n3. Display Directory\n4. Exit\nEnter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            cout << "Enter folder name: ";
            getline(cin, folder);
            manager.addFolder(folder);
            break;
        case 2:
            cout << "Enter folder name: ";
            getline(cin, folder);
            cout << "Enter file name: ";
            getline(cin, file);
            manager.addFileToFolder(folder, file);
            break;
        case 3:
            manager.displayDirectory();
            break;
        case 4:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice!\n";
            break;
        }
    }
    cout << endl
         << endl
         << "This program is created by 24CE141 _ JENIL VIRADIA.";
    return 0;
}
