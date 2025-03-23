//Lab10-2.cpp - displays total owed
//Created/revised by <your name> on <current date>

#include <iostream>
#include <iomanip>
using namespace std;

//prototypes
void displayOptions();
void getRegular(int windows, double price, double &total);
void getBoGo(int windows, double price, double &total);

int main()
{

    int option = 0;
    int numOrdered = 0;
    double winPrice = 0.0;
    double totalOwed;

    cout << fixed << setprecision(2);
    
    displayOptions();
        cout << "Pricing Option: ";
            cin >> option;
    if (option == 1 || option == 2)
    {
        cout << "Windows Ordered: ";
            cin >> numOrdered;
        cout << "Price of windows: ";
            cin >> winPrice;
        if (option == 1)
            getRegular(numOrdered, winPrice, totalOwed);
        else 
            getBoGo(numOrdered, winPrice, totalOwed);
    cout << "Total Owed:    " << totalOwed << endl << endl;
    }
    else
        cout << "Invalid option" << endl;
    return 0;
} //end of main function

void displayOptions()
{
    cout << "Pricing options:" << endl;
    cout << "1   Regular pricing" << endl;
    cout << "2   BoGo pricing" << endl;
}

void getRegular(int windows, double price, double &total)
{
    total = windows * price;
}
void getBoGo(int windows, double price, double &total)
{
    total = (windows / 2 + windows % 2) * price;
}
    
