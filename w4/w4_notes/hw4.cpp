
#include <iostream>
#include <iomanip>
#include <fstream> // save files
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cstdlib>

using namespace std;

class calc{

    public:
    calc ();

    void generate(int const);
    void print(int const);
    void ascend(int const); 
    void descend(int const);
    void flip(int const);
    void avgWolasttwo(int const);
    void save(int const);
    void load(int const);
    void add(calc, calc);
    void subtract(calc, calc);

    private:
    int randNums[10];
    double average;

};

// a.   A default constructor which sets all the array elements to 0.
calc::calc() 
{
    for (int i = 0; i < 10; i++)
        randNums[i] = 0;
}

// b.   Pick 10 random integers from 1 to 100 to be loaded into the array.
void calc::generate(int const arraySize = 10)
{
    for (int i = 0; i < arraySize; i++)
        randNums[i] = rand() % 100 + 1;
}

//c.    Print the array.
void calc::print(int const arraySize = 10)
{
    for (int i = 0; i < arraySize; i++)
        cout << randNums[i] << " ";
    cout << endl << endl;
}

// d.   Sort the array in ascending order and print the sorted array.
void calc::ascend(int const arraySize = 10)
{
    int t, i, j;
    for (i = 0; i < arraySize; i++)
        for (j = 0; j < arraySize - 1; j++)
            if (randNums[j+1] < randNums[j])
            {
                t = randNums[j+1];
                randNums[j+1] = randNums[j];
                randNums[j] = t;
            }
}

// e.   Sort the array in descending order and print the sorted array.
void calc::descend(int const arraySize = 10)
{
    int t, i, j;
    for (i = 0; i < arraySize; i++)
        for (j = 0; j < arraySize - 1; j++)
            if (randNums[j] < randNums[j+1])
            {
                t = randNums[j+1];
                randNums[j+1] = randNums[j];
                randNums[j] = t;
            }
}

// f.   Find and print the average of the array with the two largest values excluded from the average calculation.
void calc::avgWolasttwo(int const arraySize = 10)
{
    double sum;

    descend();
    for (int i = 0; i < arraySize - 2; i++)
        sum += (double)randNums[i];
    average = sum/((double)(arraySize-2));
    cout << setprecision(2) << showpoint << fixed << average << endl << endl;
}

// g.   Save the array to a text file.
void calc::save(int const arraySize = 10)
{
    cout << "Save to file output.txt" << endl;
    ofstream outfile("D:\\output.txt", ios::out);
    for (int i = 0; i < arraySize; i++)
        outfile << randNums[i] << " ";
    outfile.close();
}

// h.   Retrieve the array from the text file and print the array.
void calc::load(int const arraySize = 10)
{
    cout << "Load from file output.txt" << endl;
    ifstream infile("D:\\output.txt", ios::in);
    for (int i = 0; i < arraySize; i++)
        cout << randNums[i] << " ";
	cout << endl << endl;
    infile.close();
}

// i.   Add the corresponding elements of two arrays and store the sums into a separate object.
void calc::add(calc a, calc b)
{    
    for (int i = 0; i < 10; i++)
        randNums[i] = a.randNums[i] + b.randNums[i];
}

// j.   Subtract the corresponding elements of two arrays and store the differences into a separate object.
void calc::subtract(calc a, calc b)
{
    for (int i = 0; i < 10; i++)
        randNums[i] = a.randNums[i] - b.randNums[i];
}

// k.    Reverse the order of the array elements.
void calc::flip(int const arraySize = 10)
{
    int temp[arraySize], j = 0;

    for (int i = 0; i < arraySize; i++)
        temp[i] = randNums[i];

    for (int i = arraySize - 1; i >= 0; i--)
    {
        randNums[i] = temp[j];
        j++;
    }
}

int main()
{
    srand(time(NULL));
    calc a, b, c;

    // Method c
    cout << "Original array (a) " << endl;
    a.generate();
    a.print();

    // Method d
    cout << "Ascending order " << endl;
    a.ascend();
    a.print();

    // Method e
    cout << "Descending order " << endl;
    a.descend();
    a.print();

    // Method f
    cout << "Average excluding the last two numbers " << endl;
    a.avgWolasttwo();

    // Method g
    a.save();

    // Method h
    a.load();

    // Second array
    cout << "Second array (b) " << endl;
    b.generate();
    b.print();

    // Method i
    cout << endl << "Sum of a + b " << endl;
    c.add(a, b);
    c.print();

    // Method j
    cout << endl << "Difference of a - b " << endl;
    c.subtract(a, b);
    c.print();

    // Method k
    cout << endl << "Flip" << endl;
    a.flip();
    a.print();

    // Each array is printed after method k is called
    cout << endl << "Array for a" << endl;
    a.print();

    cout << endl << "Array for b" << endl;
    b.print();

    cout << endl << "Array for c" << endl;
    c.print();

    return 0;
}

/*

Original array (a)
24 83 59 67 92 53 67 13 63 47

Ascending order
13 24 47 53 59 63 67 67 83 92

Descending order
92 83 67 67 63 59 53 47 24 13

Average excluding the last two numbers 
66.38

Save to file output.txt
Load from file output.txt
92 83 67 67 63 59 53 47 24 13

Second array (b)
21 39 67 50 51 87 99 53 99 52


Sum of a + b
113 122 134 117 114 146 152 100 123 65 


Difference of a - b
71 44 0 17 12 -28 -46 -6 -75 -39       


Flip
13 24 47 53 59 63 67 67 83 92


Array for a
13 24 47 53 59 63 67 67 83 92 


Array for b
21 39 67 50 51 87 99 53 99 52


Array for c
71 44 0 17 12 -28 -46 -6 -75 -39

*/