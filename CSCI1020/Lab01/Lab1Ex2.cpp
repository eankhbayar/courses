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
    int x;
    cout << "Input x:\n";
    cin >> x;
    if (x % 2 == 0)
    {
        double ans = x * 2 - 1;
        ans /= 2 * x;
        printf("f(x) = %.4f\n", ans);
    }
    else
    {
        double ans = sqrt(x * x * 4 + 1);
        printf("f(x) = %.4f\n", ans);
    }
}