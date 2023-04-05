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
    int *array;
    int n, m;
    while (cout << "Input n:\n", cin >> n)
    {
        int freq = 0;
        if (n == 0)
            break;
        cout << "Input the array:\n";
        array = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> array[i];
        }
        cout << "Input m:\n";
        cin >> m;
        for (int i = 0; i < n; i++)
        {
            if (array[i] == m)
                freq++;
        }
        cout << "Frequency = " << freq << endl;
    }
    cout << "Program Terminates." << endl;
}