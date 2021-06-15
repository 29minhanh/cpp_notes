/* 
Homework Program 1
Name: Minh Anh Bui 
ID number: 1215994
*/

#include<iostream>
#include<iomanip>
using namespace std;

struct employee
{
    char fName[30], lName[30], dep[30];
    float cIncome, nIncome, raiseRate, raiseAmount;
    float lraiseAmount, sraiseAmount;
};

struct stats
{
    float tcIncome = 0, tnIncome = 0, traiseAmount = 0;
    float avgraiseAmount;
};

void input(struct employee e[5]);
void calc(struct employee e[5], struct stats t[5]);
void sort(struct employee e[5]);
void print (struct employee e[5], struct stats t[5]);

int main ()
{
    int i;
    struct employee e[5];
    struct stats t[5];

    cout << setprecision(2) << showpoint << fixed;
    input(e);
    calc(e, t);
    sort(e);
    print(e, t);

    return 0;
}

void input(struct employee e[5])
{
    int i;

    for (i = 0; i < 5; i++)
    {
        cout << "Enter the first name of the employee: ";
        cin.getline(e[i].fName, 30);

        cout << "Enter the last name of the employee: ";
        cin.getline(e[i].lName, 30);

        cout << "Enter the department the employee works in: ";
        cin >> e[i].dep;
        cin.ignore(10, '\n');

        cout << "Enter the current yearly income of the employee: ";
        cin >> e[i].cIncome;

        cout << "Enter the raise rate the employee will receive: ";
        cin >> e[i].raiseRate;
        cin.ignore(10, '\n');

        cout << endl;
    }

};

void print (struct employee e[5], struct stats t[5])
{
    int i;

    cout << "RESULTS" << endl;

    for (i = 0; i < 5; i++)
    {
        cout << "Name: " << e[i].fName << " " << e[i].lName << endl;
        cout << "Department: " << e[i].dep << endl;
        cout << "Current yearly income: $" << e[i].cIncome << endl;
        cout << "Raise percentage: " << e[i].raiseRate << "%" << endl;
        cout << "Raise amount: $" << e[i].raiseAmount << endl;
        cout << "New pay amount: $" << e[i].nIncome << endl << endl;
    }

    cout << "Logistics: " << endl;
    cout << "Average raise amount: $" << t->avgraiseAmount << endl;
    cout << "Total raise amount: $" << t->traiseAmount << endl;
    cout << "Total current income: $" << t->tcIncome << endl;
    cout << "Total new income: $" << t->tnIncome << endl << endl;
};

void calc(struct employee e[5], struct stats t[5])
{
    int i;

    for (i = 0; i < 5; i++)
    {
        e[i].raiseAmount = e[i].cIncome * e[i].raiseRate /((float)(100));
        e[i].nIncome = e[i].cIncome + e[i].raiseAmount;

        t->tcIncome += e[i].cIncome;
        t->tnIncome += e[i].nIncome;
        t->traiseAmount += e[i].raiseAmount;
    }

    t->avgraiseAmount = t->traiseAmount/((float)(5));
}

void sort(struct employee e[5])
{
    int i, j;
    float t;
    float temp_raiseAmount[5];

    for (i = 0; i < 5; i++)
        temp_raiseAmount[i] = e[i].raiseAmount;


    for (i = 0; i < 5; i++)
    {        
        for (j = 0; j < 5; j++)
        {
            if (temp_raiseAmount[j] > temp_raiseAmount[j+1])
            {
                t = temp_raiseAmount[j];
                temp_raiseAmount[j] = temp_raiseAmount[j+1];
                temp_raiseAmount[j+1] = t;
            }
        }
    }
        
    e->lraiseAmount = temp_raiseAmount[5];
    e->sraiseAmount = temp_raiseAmount[0];

}

/*
Test run: 

Enter the first name of the employee: James
Enter the last name of the employee: Kobe
Enter the department the employee works in: Accounting
Enter the current yearly income of the employee: 66111.54
Enter the raise rate the employee will receive: 6.6

Enter the first name of the employee: Walton
Enter the last name of the employee: Lebron
Enter the department the employee works in: Marketing
Enter the current yearly income of the employee: 89224.17
Enter the raise rate the employee will receive: 4.8

Enter the first name of the employee: Rondo
Enter the last name of the employee: Luke
Enter the department the employee works in: Sales
Enter the current yearly income of the employee: 75123.25
Enter the raise rate the employee will receive: 7.4

Enter the first name of the employee: Bryant
Enter the last name of the employee: Kyle
Enter the department the employee works in: Sales
Enter the current yearly income of the employee: 69644.44
Enter the raise rate the employee will receive: 5.5

Enter the first name of the employee: Kuzma
Enter the last name of the employee: Rajon
Enter the department the employee works in: Marketing
Enter the current yearly income of the employee: 96222.77
Enter the raise rate the employee will receive: 3.9

RESULTS
Name: James Kobe
Department: Accounting
Current yearly income: $66111.54
Raise percentage: 6.60%
Raise amount: $4363.36
New pay amount: $70474.90

Name: Walton Lebron
Department: Marketing
Current yearly income: $89224.17
Raise percentage: 4.80%
Raise amount: $4282.76
New pay amount: $93506.93

Name: Rondo Luke
Department: Sales
Current yearly income: $75123.25
Raise percentage: 7.40%
Raise amount: $5559.12
New pay amount: $80682.37

Name: Bryant Kyle
Department: Sales
Current yearly income: $69644.44
Raise percentage: 5.50%
Raise amount: $3830.44
New pay amount: $73474.88

Name: Kuzma Rajon
Department: Marketing
Current yearly income: $96222.77
Raise percentage: 3.90%
Raise amount: $3752.69
New pay amount: $99975.46

Logistics:
Average raise amount: $4357.67
Total raise amount: $21788.37
Total current income: $396326.19
Total new income: $418114.53
*/