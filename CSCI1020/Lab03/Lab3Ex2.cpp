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
Date: 16/02/2023
***********************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

double factorial(int n)
{
    double result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

double estimateE(double x, int n)
{
    double result = 0;
    for (int i = 0; i < n; i++)
    {
        result += pow(x, i) / factorial(i);
    }
    return result;
}

int main()
{
    double x;
    int n;

    cout << "Please enter x:" << endl;
    cin >> x; // Assume that x is a floating-point number
    cout << "Please enter n:" << endl;
    cin >> n; // Assume that n is a positive integer
    cout << "Result:" << endl;
    cout << estimateE(x, n) << endl;
    return 0;
}