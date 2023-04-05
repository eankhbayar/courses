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
    int a;
    cout << "Input a number:\n";
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < a - i; j++)
        {
            if (j + 1 == a - i)
                cout << "*";
            else
                cout << "*.";
        }
        cout << endl;
    }
}
