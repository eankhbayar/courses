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
/* Update the current time to the next second.
 The function returns true when the next second starts a new day.
 Otherwise, returns false. */
bool nextTick(int &hour, int &minute, int &second)
{
    second++;
    if (second == 60)
    {
        second = 0;
        minute++;
        if (minute == 60)
        {
            minute = 0;
            hour++;
            if (hour == 24)
            {
                hour = 0;
                return true;
            }
        }
    }
    return false;
}
/* The main() function. No modification is allowed except the case for scanf_s(). */
int main()
{
    int h, m, s, n;
    cout << "Enter start time (h:m:s):" << endl;
    /* For other IDE/C++ compiler, you may need to change scanf_s() to scanf()
     scanf_s() and scanf() are the C-style ways to read user input */
    scanf("%d", &h);  // Read the first integer and store it in "h"
    scanf(":%d", &m); // Read the second integer after : and it store in "m"
    scanf(":%d", &s); // Read the third integer after : and it store in "s"
    cout << "Enter n:" << endl;
    cin >> n;
    cout << "Output:" << endl;
    for (int i = 0; i < n; i++)
    {
        if (nextTick(h, m, s))
            cout << "A new day begins" << endl;
        printf("%02d:%02d:%02d\n", h, m, s); // Print a padding 0 for 1 digit number
    }
    return 0;
}