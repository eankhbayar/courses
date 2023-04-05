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
Date: 09/02/2023
***********************************************************************/

#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cout << "Input two numbers:\n";
    cin >> a >> b;
    // print numbers divisible by 5 between a and b
    cout << "Output:\n";
    int cnt = 0;
    if (a > b)
    {
        for (int i = a; i >= b; i--)
        {
            if (i % 5 == 0)
            {
                cout << i << endl;
                cnt++;
            }
        }
    }
    else
    {
        for (int i = a; i <= b; i++)
        {
            if (i % 5 == 0)
            {
                cout << i << endl;
                cnt++;
            }
        }
    }
    if (cnt == 0)
    {
        cout << "N/A" << endl;
        return 0;
    }
    else
    {
        return 0;
    }
}
