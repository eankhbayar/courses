/***********************************************************************
CSCI1020 Hands-on Introduction to C++
I declare that the source code here submitted is original except for
source material explicitly acknowledged. I also acknowledge that I am
aware of University policy and regulations on honesty in academic work,
and of the disciplinary guidelines and procedures applicable to breaches
of such policy and regulations, as contained in the following University
website:
https://www.cuhk.edu.hk/policy/academichonesty/
Student Name: Ankhbayar ENKHTAIVAN
Student ID: 1155185142
Date: 02/03/2023
***********************************************************************/

#include <iostream>
using namespace std;

int main()
{
    int *array1, *array2, *array3;

    int n;
    cout << "Input n: " << endl;
    cin >> n;

    array1 = new int[n];
    array2 = new int[n];
    array3 = new int[n + n];

    cout << "Please enter array1:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> array1[i];
    }
    cout << "Please enter array2:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> array2[i];
    }
    int j = 0, i = 0;
    for (int x = 0; x < n + n; x++)
    {
        if (i == n)
        {
            array3[x] = array2[j];
            j++;
        }
        else if (j == n)
        {
            array3[x] = array1[i];
            i++;
        }
        else if (array1[i] < array2[j])
        {
            array3[x] = array1[i];
            i++;
        }
        else
        {
            array3[x] = array2[j];
            j++;
        }
    }

    cout << "array1: ";
    for (int i = 0; i < n; i++)
    {
        cout << array1[i] << " ";
    }
    cout << endl;
    cout << "array2: ";
    for (int i = 0; i < n; i++)
    {
        cout << array2[i] << " ";
    }
    cout << endl;
    cout << "array3: ";
    for (int i = 0; i < n + n; i++)
    {
        cout << array3[i] << " ";
    }
    cout << endl;
    delete[] array1;
    array1 = NULL;
    delete[] array2;
    array2 = NULL;
    delete[] array3;
    array3 = NULL;
    return 0;
}