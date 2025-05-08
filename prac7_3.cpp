#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const int NAME_LENGTH = 50;
const char *FILENAME = "inventory.txt";
class Product
{
public:
    char name[NAME_LENGTH];
    int quantity;
    float price;
    Product()
    {
        strcpy(name, "");
        quantity = 0;
        price = 0.0f;
    }
    void input()
    {
        cout << "Enter product name: ";
        cin.ignore();
        cin.getline(name, NAME_LENGTH);
        cout << "Enter quantity: ";
        cin >> quantity;
        cout << "Enter price: ";
        cin >> price;
    }
    void display() const
    {
        cout << "Name: " << name << ", Quantity: " << quantity << ", Price: $" << price << endl;
    }
    void writeToFile(ofstream &out) const
    {
        out << name << "," << quantity << "," << price << endl;
    }
    bool loadFromLine(const char *line)
    {
        char temp[100];
        strcpy(temp, line);
        char *token = strtok(temp, ",");
        if (!token)
            return false;
        strcpy(name, token);

        token = strtok(NULL, ",");
        if (!token)
            return false;
        quantity = atoi(token);

        token = strtok(NULL, ",");
        if (!token)
            return false;
        price = atof(token);

        return true;
    }
    bool matchesName(const char *searchName) const
    {
        return strcmp(name, searchName) == 0;
    }
};
class Inventory
{
private:
    Product *products;
    int capacity;
    int count;
    void resize()
    {
        int newCapacity = capacity * 2;
        Product *newArray = new Product[newCapacity];
        for (int i = 0; i < count; ++i)
            newArray[i] = products[i];
        delete[] products;
        products = newArray;
        capacity = newCapacity;
    }

public:
    Inventory()
    {
        capacity = 10;
        count = 0;
        products = new Product[capacity];
    }

    ~Inventory()
    {
        delete[] products;
    }
    void addProduct()
    {
        Product p;
        p.input();
        ofstream outFile(FILENAME, ios::app);
        if (!outFile)
        {
            cerr << "Error: Unable to open file for writing." << endl;
            return;
        }
        p.writeToFile(outFile);
        outFile.close();
        if (count == capacity)
            resize();
        products[count++] = p;
        cout << "Product added successfully.\n";
    }
    void loadFromFile()
    {
        ifstream inFile(FILENAME);
        if (!inFile)
        {
            cerr << "Error: Inventory file not found." << endl;
            return;
        }
        count = 0;
        char line[100];
        while (inFile.getline(line, sizeof(line)))
        {
            Product p;
            if (p.loadFromLine(line))
            {
                if (count == capacity)
                    resize();
                products[count++] = p;
            }
        }
        inFile.close();
    }
    void viewInventory()
    {
        loadFromFile();
        if (count == 0)
        {
            cout << "Inventory is empty.\n";
            return;
        }
        cout << "\n--- Inventory List ---\n";
        for (int i = 0; i < count; ++i)
            products[i].display();
    }
    void searchProduct()
    {
        char searchName[NAME_LENGTH];
        cout << "Enter product name to search: ";
        cin.ignore();
        cin.getline(searchName, NAME_LENGTH);
        loadFromFile();
        bool found = false;
        for (int i = 0; i < count; ++i)
        {
            if (products[i].matchesName(searchName))
            {
                cout << "\nProduct found:\n";
                products[i].display();
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Product \"" << searchName << "\" not found.\n";
    }
};
int main()
{
    Inventory inv;
    int choice;
    do
    {
        cout << "\n--- Inventory Management System ---\n";
        cout << "1. Add Product\n";
        cout << "2. View Inventory\n";
        cout << "3. Search Product\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            inv.addProduct();
            break;
        case 2:
            inv.viewInventory();
            break;
        case 3:
            inv.searchProduct();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid option. Try again.\n";
            break;
        }
    } while (choice != 0);
    cout << endl
         << endl
         << "This program is created by 24CE141 _ JENIL VIRADIA.";
    return 0;
}
