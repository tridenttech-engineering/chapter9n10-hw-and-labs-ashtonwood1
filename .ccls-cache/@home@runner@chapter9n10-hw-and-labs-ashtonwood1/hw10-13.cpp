//Lab 9-2.cpp - displays two monthly car payments
//Created/revised by <Ashton Wood> on <11/19/2024>

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
    cout << "Monthly Credit Union payment: $" 
        << creditPayment << endl;
    cout << "Monthly Dealer payment: $"
        << dealerPayment << endl;
    
    return 0;
}//end of main function    

    //*****function definitions*****
double getPayment(int prin,
                  double monthRate, 
                  int months)

{
    //calculates and returns a monthly payment
    double roundedPay=0.0;
    double monthPay = 0.0;
    roundedPay = static_cast<int>((monthPay + .005) * 100) / 100.0;
    monthPay = prin * monthRate / 
        (1 - pow(monthRate + 1, -months));
    return monthPay;
} //end of getPayment function//*****function definition*****
