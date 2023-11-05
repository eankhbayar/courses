
/**
 * ENGG1110 Problem Solving by Programming
 *
 * I declare that the assignment here submitted is original
 * except for source material explicitly acknowledged,
 * and that the same or closely related material has not been
 * previously submitted for another course.
 * I also acknowledge that I am aware of University policy and
 * regulations on honesty in academic work, and of the disciplinary
 * guidelines and procedures applicable to breaches of such
 * policy and regulations, as contained in the website.
 *
 * University Guideline on Academic Honesty:
 * http://www.cuhk.edu.hk/policy/academichonesty/
 *
 * Student Name : Ankhbayar Enkhtaivan
 * Student ID   : 1155185142
 * Class/Section: ENGG1110D
 * Date         : 30/03/2023
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  This function returns 1 if all the characters in input[11] are numeric (0-9),
  otherwise 0.
 */
int isnumeric(char input[11])
{
    // INPUT YOUR CODE HERE
    // check whether all the characters in input[11] are numeric (0-9)
    // return 1 if all the characters are numeric; otherwise return 0
    // ...

    int tmp = 1;
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] < '0' || input[i] > '9')
        {
            tmp = 0;
        }
    }
    return tmp;

    // END OF YOUR CODE
}

// You may add other helper functions here as needed.

/* starting point of this C program */
int main(void)
{
    // Enter your code below
    // define flags to check whether to continue

    printf("Guess my age?\n");

    // print "Guess my age?"

    while (1)
    {
        char input[11];
        scanf("%s", input);
        if (isnumeric(input) == 1)
        {
            int guess = atoi(input);
            if (guess == 7)
            {
                printf("You got it!\n");
                break;
            }
            else
            {
                printf("Nope\n");
            }
        }
        else
        {
            printf("NaN\n");
        }
    }

    // while the input is invalid or guess is not 7
    // -- set up your infinite loop with corresponding print out
    // ...

    /* last statement of this C program */
    return 0;
}
