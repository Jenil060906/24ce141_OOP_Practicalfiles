#include <iostream>
using namespace std;

class Inventory
{
     int Product_Id, quantity;
     char Product_Name[25];
     float price;

public:
     void Add_Product()
     {
          cout << "\nEnter product ID: ";
          cin >> Product_Id;
          cout << "Enter product name: ";
          cin >> Product_Name;
          cout << "Enter product quantity: ";
          cin >> quantity;
          cout << "Enter product price: ";
          cin >> price;
     }

     void Update_Quantity()
     {
          int New_Quantity;
          char choice;
          cout << "\nEnter the quantity to be added or removed: ";
          cin >> New_Quantity;
          cout << "Enter your choice to add or remove (A/R): ";
          cin >> choice;

          switch (choice)
          {
          case 'A':
          case 'a':
               quantity += New_Quantity;
               cout << "New quantity is: " << quantity << endl;
               break;
          case 'R':
          case 'r':
               if (New_Quantity > quantity)
               {
                    cout << "Error: Not enough stock to remove.\n";
               }
               else
               {
                    quantity -= New_Quantity;
                    cout << "New quantity is: " << quantity << endl;
               }
               break;
          default:
               cout << "Invalid choice. Use 'A' to add or 'R' to remove.\n";
          }
     }

     void Calculate_Total_Price()
     {
          float Total_Price = quantity * price;
          cout << "\nTotal value of product [" << Product_Name << "] is: $" << Total_Price << endl;
     }

     void Display_Product()
     {
          cout << "\nProduct ID: " << Product_Id
               << "\nProduct Name: " << Product_Name
               << "\nQuantity: " << quantity
               << "\nPrice per unit: $" << price << endl;
     }
};

int main()
{
     Inventory S[100];
     int n;

     cout << "Enter number of products: ";
     cin >> n;

     for (int i = 0; i < n; i++)
     {
          cout << "\n--- Enter details for product " << i + 1 << " ---";
          S[i].Add_Product();
     }

     int choice;
     do
     {
          cout << "\n--- Inventory Menu ---";
          cout << "\n1. Update Quantity";
          cout << "\n2. Calculate Total Price";
          cout << "\n3. Display Product Info";
          cout << "\n4. Exit";
          cout << "\nEnter your choice (1-4): ";
          cin >> choice;

          if (choice >= 1 && choice <= 3)
          {
               int index;
               cout << "Enter product index (1 to " << n << "): ";
               cin >> index;
               if (index < 1 || index > n)
               {
                    cout << "Invalid product index.\n";
                    continue;
               }

               switch (choice)
               {
               case 1:
                    S[index - 1].Update_Quantity();
                    break;
               case 2:
                    S[index - 1].Calculate_Total_Price();
                    break;
               case 3:
                    S[index - 1].Display_Product();
                    break;
               }
          }
          else if (choice != 4)
          {
               cout << "Invalid choice. Try again.\n";
          }

     } while (choice != 4);
     cout << endl
          << endl
          << "This program is created by 24CE141 _ JENIL VIRADIA.";
     return 0;
}
