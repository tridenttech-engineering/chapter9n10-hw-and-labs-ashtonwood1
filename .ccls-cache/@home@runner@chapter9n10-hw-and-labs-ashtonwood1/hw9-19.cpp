//Lab 9-2.cpp - displays two monthly car payments
//Created/revised by <Ashton Wood> on <11/19/2024>
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
    double totalCreditPayment = 0.0;
    double totalDealerPayment = 0.0;

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

    //calculate total payments
    totalCreditPayment = getTotal(creditPayment, term); // Pass only the term in years
    totalDealerPayment = getTotal(dealerPayment, term); // Pass only the term in years

    //display payments
    cout << fixed << setprecision(2) << endl;
    cout << "Credit union payment: $"
        << creditPayment << endl;
    cout << "Total Credit union payment: $"
        << totalCreditPayment << endl;
    cout << "Dealer payment: $"
        << dealerPayment << endl;
    cout << "Total dealer payment: $"
        << totalDealerPayment << endl;
    return 0;
}//end of main function

//*****function definitions*****
double getPayment(int prin,
                  double monthRate,
                  int term)
{
    //calculates and returns a monthly payment
    double monthPay = 0.0;
    double denominator = 0.0;

    denominator = 1 - pow(monthRate + 1, -term);
    if (denominator != 0)
        monthPay = prin * monthRate / denominator;
    else
        monthPay = -1;
    return monthPay;
}	//end of getPayment function

double getTotal(double monthPay, int term)
{
    double total = 0.0;
    double roundedPay = 0.0;
    roundedPay = static_cast<int>((monthPay + 0.005) * 100) / 100.0;
    total = roundedPay * term * 12; // Calculate total using the term in years (multiply by 12)
    return total;
} //end of getTotal function