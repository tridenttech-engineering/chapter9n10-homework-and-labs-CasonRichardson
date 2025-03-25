//Lab 9-2.cpp - displays two monthly car payments
//Created/revised by <your name> on <current date>

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//function prototype
double getPayment(int, double, int);
double getTotal(double, int);

int main()
{
    //declare variables
    int carPrice = 0;
    int rebate = 0;
    double creditRate = 0.0;
    double dealerRate = 0.0;
    int term = 0;
    double creditPayment = 0.0;
    double dealerPayment = 0.0;
    double uniontotalPaid = 0.0;
    double dealertotalPaid = 0.0;
    

    cout << "Car price (after any trade-in): ";
    cin >> carPrice;
    cout << "Rebate: ";
    cin >> rebate;
    cout << "Credit union rate: ";
    cin >> creditRate;
    cout << "Dealer rate: ";
    cin >> dealerRate;
    cout << "Term in years: ";
    cin >> term;

    //call function to calculate payments
    creditPayment = getPayment(carPrice - rebate,
        creditRate / 12, term * 12);
    dealerPayment = getPayment(carPrice, 
        dealerRate / 12, term * 12);    //assign values to calculate payments

    
    //display payments 
    cout << fixed << setprecision(2) << endl; 
    cout << "Credit union payment: $" 
        << creditPayment << endl;
    cout << "Dealer payment: $"
        << dealerPayment << endl;

    uniontotalPaid = creditPayment * term * 12;
    dealertotalPaid = dealerPayment * term * 12;

     cout << "Total paid using Credit Union: $"
        << uniontotalPaid << endl;
    cout << "Total paid uing Dealership: $"
        << dealertotalPaid << endl;
    
    return 0;
}//end of main function    

    //*****function definitions*****
double getPayment(int prin, double monthRate, int months)
{
    //calculates and returns a monthly payment

    if (monthRate > 0) {
    return prin * monthRate /  (1 - pow(1 + monthRate, -months));
    }
    else {
    return -1;
    }
}
double getTotal(double monthPay, int months)
{
    double total;
    double roundedPay;
    
    roundedPay = static_cast<int>((monthPay + .005) * 100) / 100.0;
    total = roundedPay * months;
    return total;
}
