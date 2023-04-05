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
    cout << "Please enter the number of rows:\n";
    int n, m;
    cin >> n;
    cout << "Please enter the number of columns:\n";
    cin >> m;
    int arr[n][m];
    cout << "Please enter the array elements:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += arr[j][i];
        }
        cout << sum << " ";
    }
    cout << endl;
}