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
Date: 23/02/2023
***********************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, d;
    cout << "Please enter the array size:" << endl;
    cin >> n;
    int arr[n];
    cout << "Please enter the array elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Please enter d:" << endl;
    cin >> d;
    int tmp = 0;
    cout << "Output:\n";
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] % d == 0)
        {
            cout << arr[i] << endl;
            tmp++;
        }
    }
    if (tmp == 0)
    {
        cout << "N/A" << endl;
    }
}
