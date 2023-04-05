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
Date: 02/02/2023
***********************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a, b, c;
    cout << "Input three numbers:\n";
    cin >> a >> b >> c;
    if (a == b && b == c)
    {
        cout << "Triple" << endl;
        return 0;
    }
    if (a == b)
    {
        if (a % 2 == 0)
        {
            cout << "Even Double" << endl;
            return 0;
        }
        else
        {
            cout << "Odd Double" << endl;
            return 0;
        }
    }
    if (a == c)
    {
        if (a % 2 == 0)
        {
            cout << "Even Double" << endl;
            return 0;
        }
        else
        {
            cout << "Odd Double" << endl;
            return 0;
        }
    }
    if (b == c)
    {
        if (b % 2 == 0)
        {
            cout << "Even Double" << endl;
            return 0;
        }
        else
        {
            cout << "Odd Double" << endl;
            return 0;
        }
    }
    cout << "Single" << endl;
}