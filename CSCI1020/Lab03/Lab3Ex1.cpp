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
using namespace std;

/* Print a triangle with the specified size (= the number of rows)
 Return the number of stars printed */
int printTriangle(int size)
{
    int numOfStars = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
            numOfStars++;
        }
        cout << endl;
    }
    return numOfStars;
}

int main()
{
    int a;
    cout << "Input n:\n";
    cin >> a;
    int numOfStars = 0;
    for (int i = 1; i <= a; i++)
    {
        numOfStars += printTriangle(i + 1);
    }
    cout << "Number of stars = " << numOfStars << endl;
}
