/*
Minh Anh Bui
Studenet ID: 1215994
Exam 3
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include <iomanip>
using namespace std;

class stock
{
    public: 
    stock(const char * = " ", float = 0.0, float = 0.0, float = 0.0); 
    ~stock();
    void random();
    void outPriv();
    void calc(float);

    void setdata(char, float, float, float);

    private:
    char stName[30];
    float noShares, buyPrice, curPrice, totCost, curVal, profit;
    float change;
};

// 1. A default constructor with default arguments which set the stock name to " " and the numeric private data members to 0.0.
stock::stock(const char *sn, float ns, float bp, float cp)
{   
    strcpy(stName, sn);
    noShares = ns; 
    buyPrice = bp;
    curPrice = cp;
    calc(0);
}

// 2. A destructor that prints the stock name only for the object being destructed.
stock::~stock()
{
    cout << endl << stName << " is destroyed" << endl;
}

// 3. A method print which prints out all the private data members of the class.
void stock::outPriv()
{
    cout << setprecision(2) << showpoint << fixed;

    cout << "Name: " << stName << endl;
    cout << "Number of shares: " << noShares << endl;
    cout << "Buy price: $" << buyPrice << endl; 
    cout << "Current price: $" << curPrice << endl;
    cout << "Total cost: $" <<  totCost << endl;
    cout << "Current value: $" << curVal << endl;
    cout << "Profit: $" << profit << endl;
}

/*
4. A method calc which will recalculate the necessary private data members when the 
user enters the change in the current price of the stock.
*/
void stock::calc(float exch)
{
    curPrice = curPrice + exch;
    totCost = noShares*buyPrice;
    curVal = noShares*curPrice;
    profit = curVal - totCost;

    outPriv();
}

int main ()
{
    float exch;
    stock s("Joe's Technology", 150.0, 69.34, 77.55); 

    /* The user should be prompted for the change in the current price of the 
    stock in the main. Please assume valid input is entered by the user and 
    use parameter passing. */

    cout << endl << "Enter the change in the current price: ";
    cin >> exch;
    cout << endl;
    s.calc(exch);

    return 0;
}

/*

Name: Joe's Technology
Number of shares: 150.00
Buy price: $69.34
Current price: $77.55
Total cost: $10401.00
Current value: $11632.50
Profit: $1231.50

Enter the change in the current price: -0.55

Name: Joe's Technology
Number of shares: 150.00
Buy price: $69.34
Current price: $77.00
Total cost: $10401.00
Current value: $11550.00
Profit: $1149.00

Joe's Technology is destroyed

*/
