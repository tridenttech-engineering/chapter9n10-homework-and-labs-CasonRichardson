//Lab 9-2.cpp - displays two monthly car payments
//Created/revised by <your name> on <current date>

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double getPayment(int prin, double monthRt, int months);

int main()
{

int carPrice = 0;
int rebate = 0;
double unionRt = 0.0;
double dealerRt = 0.0;
int term = 0;

double unionPay = 0.0;
double dealerPay = 0.0;

cout << "Car Price: ";
    cin >> carPrice;
cout << "Rebate: ";
    cin >> rebate;
cout << "Credit Union Rate (as decimal): ";
    cin >> unionRt;
cout << "Dealer Rate (as decimal): ";
    cin >> dealerRt;
cout << "Term (in years): ";
    cin >> term;
    
unionPay = getPayment(carPrice - rebate, unionRt / 12, term * 12);

dealerPay = getPayment(carPrice - rebate, dealerRt / 12, term * 12);

cout << "Union Pay: $" << unionPay << endl;
cout << "Dealer Pay: $" << dealerPay << endl;

    return 0;
}//end of main function    

double getPayment(int prin, double monthRt, int months)
{
    double monthPay = 0.0;

    monthPay = prin * monthRt / (1 - pow(monthRt +1, -months));
    return monthPay;
}
