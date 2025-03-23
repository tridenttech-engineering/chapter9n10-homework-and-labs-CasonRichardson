//Lab 9-2.cpp - displays two monthly car payments
//Created/revised by <your name> on <current date>

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//function prototype
double getPayment(int, double, int);

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

    //calculate what the user will pay in total

    uniontotalPaid = creditPayment * term * 12;
    dealertotalPaid = dealerPayment * term * 12;
    
    //display payments
    cout << fixed << setprecision(2) << endl; 
    cout << "Credit union payment: $" 
        << creditPayment << endl;
    cout << "Dealer payment: $"
        << dealerPayment << endl;
    cout << "Total paid using Credit Union: $"
        << uniontotalPaid << endl;
    cout << "Total paid uing Dealership: $"
        << dealertotalPaid << endl;
    
    return 0;
}//end of main function    

    //*****function definitions*****
double getPayment(int prin,
                  double monthRate, 
                  int months)
{
    //calculates and returns a monthly payment
    double monthPay = 0.0;
    double denom; //just used it as a variable for if statement

    //function defining denominator
    denom = (1-pow(monthRate + 1, -months));

        if (denom == 0) {
        return -1;
            }
        
    monthPay = prin * monthRate / denom;
   
         return monthPay;
} //end of getPayment function//*****function definition*****
