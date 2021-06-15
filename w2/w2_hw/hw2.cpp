/*
Minh Anh Bui
CS 37 
24th February 2021
Student ID: 1215994
*/

#include<iostream>
#include<fstream>
#include <cstring>
#include <string>
using namespace std;

// Function prototype
template <class T>
void input(T *, const int);
template <class T>
void printavg(T *, const int);
template <class T>
void sort(T *, const int);
template <class T>
void print(T *, const int);

template <class T>
void loading(T *a, const int n, int count)
{
    int i;
    char one[30] = "D:\\integers.dat";
    char two[30] = "D:\\floats.dat";
    char three[30] = "D:\\strings.dat";
    char address[30] = "D:\\failed.dat";

    if (count == 1)
        strcpy(address, one);
    if (count == 2)
        strcpy(address, two);
    if (count == 3)
        strcpy(address, three);


    cout << "Print (after saving): " << endl;
    ifstream infile((address), ios::in);
    for (i = 0; i < n; i++)
        cout << a[i] << endl;
	cout << endl;
    infile.close();
}

template <class T>
void saving(T *a, const int n, int count) // this function tries to save numbers right after you've inputted them
{
    int i;

    char one[30] = "D:\\integers.dat";
    char two[30] = "D:\\floats.dat";
    char three[30] = "D:\\strings.dat";
    char address[30] = "D:\\failed.dat";

    if (count == 1)
        strcpy(address, one);
    if (count == 2)
        strcpy(address, two);
    if (count == 3)
        strcpy(address, three);

    ofstream outfile(address, ios::out);
    for (i = 0; i < n; i++)
        outfile << a[i] << endl;
	outfile.close();

	cout << endl  << endl;
}

template <class T>
void repeat(T *a, const int n, int &count, const int steps = 4)
{
    void (*f[steps])(T *, const int) = {input, sort, printavg, print};

    for (int j = 0; j < steps; j++) // we have 5 functions, input print sort printavg, and saving
        (*f[j]) (a, n);

    count++;
}

int main ()
{
    // values of which doesn't even matter because they're going to be overwritten by the user anyway
    const int n1 = 5, n2 = 7, n3 = 6;
	int a[n1] = {2, 4, 6, 8, 10};
	float b[n2] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
	char c[n3] = "HELLO";

    int count = 0;

    repeat(a, n1, count);
    saving(a, n1, count);
    loading(a, n1, count);

    repeat(b, n2, count);
    saving(b, n2, count);
    loading(b, n2, count);

    repeat(c, n3, count);
    saving(c, n3, count);
    loading(c, n3, count);

    return 0;
}

template <class T>
void input(T *a, const int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the array data: ";
        cin >> a[i];
    }

    cout << endl;
}

template <class T> // printing out this thingy works
void print (T*a, const int n)
{
    cout << "Print (before saving): " << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << endl;
}
// 3. sort the array data in ascending order.
template <class T>
void sort(T *a, const int n)
{
    T temp;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++)
            if (a[j] > a[j+1]) // bubble sort from low to high
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }

}

// 2. print the average of the array with the two largest values excluded from the average calculation.
template <class T>
void printavg(T *a, const int n) //POG THIS WORKS
{
    T sum = 0, avg;
    int i;

    for (i = 0; i < (n-2); i++)
        sum += a[i];

    avg = sum / i;

    cout << "Average (excluding biggest two number): " << avg << endl << endl;

}

/*

PS C:\Users\minha\Desktop\CS37\week2\hw2> ./hw2   
Enter the array data: 1
Enter the array data: 2
Enter the array data: 3
Enter the array data: 4
Enter the array data: 235

Average (excluding biggest two number): 2

Print (before saving): 
1
2
3
4
235


Print (after saving):
1
2
3
4
235

Enter the array data: ^LE
PS C:\Users\minha\Desktop\CS37\week2\hw2> g++ -o hw2 hw2.cpp
PS C:\Users\minha\Desktop\CS37\week2\hw2> ./hw2
Enter the array data: 2
Enter the array data: 53
Enter the array data: 45
Enter the array data: 12
Enter the array data: 53

Average (excluding biggest two number): 19

Print (before saving):
2
12
45
53
53


Print (after saving): 
2
12
45
53
53

Enter the array data: 2.5
Enter the array data: 3.4
Enter the array data: 2.6
Enter the array data: 1.2
Enter the array data: 54.3
Enter the array data: 2.8
Enter the array data: 3.2

Average (excluding biggest two number): 2.46

Print (before saving): 
1.2
2.5
2.6
2.8
3.2
3.4
54.3


Print (after saving):
1.2
2.5
2.6
2.8
3.2
3.4
54.3

Enter the array data: b
Enter the array data: u
Enter the array data: z
Enter the array data: z
Enter the array data: e
Enter the array data: r

Average (excluding biggest two number): ∞

Print (before saving):
b
e
r
u
z
z


Print (after saving):
b
e
r
u
z
z


*/