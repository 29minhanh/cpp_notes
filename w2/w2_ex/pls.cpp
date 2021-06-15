//  (7) 1. Write a function template that uses the return statement to return the smallest value in an array.  
// The array size is also passed to the function template.  Please only write the function template, no main is needed.


#include <iostream>
using namespace std;

template <class T>
T smallest(T*arr, int size)
{
    T small, temp;

    int i, j;

    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            if (arr[j+1] < arr[j])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = arr[j];
            }

    small = arr[0];

    return small;
}

int main ()
{
    int arr[4] = {5, 0, 5, 7};
    int small;
    small = smallest(arr, 4);

    cout << small;

    return 0;
}