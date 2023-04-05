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

void f(int *p1, int *p2)
{
    int temp;
    temp = *p1;
    *p1 = *p1 + *p2;
    *p2 = abs(temp - *p2);
}

int main()
{
    int a, b;
    cout << "Input a and b: ";
    cin >> a >> b;
    cout << "Before: a = " << a << ", b = " << b << endl;
    f(&a, &b);
    cout << " After: a = " << a << ", b = " << b << endl;
    return 0;
}