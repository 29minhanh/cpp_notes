#include <iostream>
#include <fstream>
using namespace std;

int main ()
{
    char name[40];
    int shares;
    double buyPrice, curPrice, totCost, curValue, profit;

    ifstream infile ("d:\\stocks.dat", ios::in);
    ofstream outfile ("d:\\profits.dat", ios::out);

    while (infile.getline(name, 50))
    {
        infile >> shares >> buyPrice >> curPrice;
        totCost = shares*buyPrice;
        curValue = shares*curPrice;
        profit = curValue - totCost;
        outfile << name << endl << totCost << ' ' << curValue << ' ' << profit << endl;
        infile.ignore(50, '\n');
    }
    infile.close();
    outfile.close();
}