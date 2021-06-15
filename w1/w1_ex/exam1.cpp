#include <iostream>
#include <iomanip>
using namespace std;

void calculate (float &, int &, float &, float &, float &, float &);

int main ()
{

    float totalcost, buyprice, currentvalue, currentprice, profit;
    int shares;

    calculate (totalcost, shares, buyprice, currentvalue, currentprice, profit);

    return 0;

}

void calculate (float &totalcost, int &shares, float &buyprice, float &currentvalue, float &currentprice, float &profit)
{

    totalcost = ((float)(shares))*buyprice;
    currentvalue = ((float)(shares))*currentprice;
    profit = currentvalue - totalcost;

}



/*
    char first[30], last[30];

    cout << "Enter the first name: " << endl;
    cin.getline(first, 30);
    cout << "Enter the last name: " << endl;
    cin.getline(last, 30);

    cout << left << setw(15) << first << " ";
    cout << setw(15) << last <<  endl;
*/

/*
    float total = 345.6789;
    cout << setprecision(2) << showpoint << fixed << "Your total amount is $" << total << endl;

*/
