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
    cout << "Please enter n:\n";
    int n;
    cin >> n;
    cout << "Please enter the arrays:\n";
    while (true)
    {
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != arr[n - 1 - i])
            {
                cout << "Program terminates.\n";
                return 0;
            }
        }
    }
}