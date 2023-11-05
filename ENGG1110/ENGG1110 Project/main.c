/**
 * ENGG1110 Problem Solving by Programming
 *
 * Course Project
 *
 * I declare that the project here submitted is original
 * except for source material explicitly acknowledged,
 * and that the same or closely related material has not been
 * previously submitted for another course.
 * I also acknowledge that I am aware of University policy and
 * regulations on honesty in academic work, and of the disciplinary
 * guidelines and procedures applicable to breaches of such
 * policy and regulations, as contained in the website.
 *
 * University Guideline on Academic Honesty:
 *   https://www.cuhk.edu.hk/policy/academichonesty/
 *
 * Student Name  : Ankhbayar Enkhtaivan
 * Student ID    : 1155185142
 * Class/Section : ENGG1110D
 * Date          : 29/03/2023
 */

#include <stdio.h>
/* NO other header files are allowed */

/* NO global variables are allowed */

/* Initialize the specified game board.
   Please design your own representation for the game board.  For example:
      - Does gameBoard[0][0] represent the top left corner or the bottom left corner of the game board?
      - Which numbers represent empty cells and crosses? */
void initGameBoard(int gameBoard[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            gameBoard[i][j] = 0;
        }
    }
    // TODO: Complete this part
}

/* Display the specified game board on the screen.
   You are required to exactly follow the output format stated in the project specification.
   IMPORTANT: Using other output format will result in mark deduction. */
void printGameBoard(int gameBoard[3][3])
{
    // |7|8|9|
    // |4|5|6|
    // |1|2|3|
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (gameBoard[i][j] == 0)
            {
                printf("|%d", (2 - i) * 3 + (j + 1));
            }
            else
            {
                if (gameBoard[i][j] == 1)
                {
                    printf("|X");
                }
            }
        }
        printf("|\n");
    }
}

/* Display the two game boards on the screen.
   Implemented for you already and no change is needed */
void printTwoGameBoards(int gameBoard1[3][3], int gameBoard2[3][3])
{
    printf("\n");
    printf("# Game Board 1 #\n");
    printGameBoard(gameBoard1);
    printf("# Game Board 2 #\n");
    printGameBoard(gameBoard2);
}

/* Return 1 if the specified game board is dead (i.e., having three-in-a-row of crosses), otherwise return 0. */
int isGameBoardDead(int gameBoard[3][3])
{
    int success = 0;
    for (int i = 0; i < 3; i++)
    {
        if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2] && gameBoard[i][0] != 0)
        {
            success = 1;
        }
        if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i] && gameBoard[0][i] != 0)
        {
            success = 1;
        }
    }
    if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2] && gameBoard[0][0] != 0)
    {
        success = 1;
    }
    if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0] && gameBoard[0][2] != 0)
    {
        success = 1;
    }
    if (success == 1)
        return success;
    return success;
}

/* Update the specific game board according to the user input.
   The user input may not be valid, but you can assume that it must be an integer. */
void updateGameBoard(int gameBoard[3][3])
{
    printf("Choose the cell:\n");
    int input;
    scanf("%d", &input);
    while (input < 1 || input > 9)
    {
        printf("Input out of range. Please input again:\n");
        scanf("%d", &input);
    }
    while (gameBoard[2 - (input - 1) / 3][(input - 1) % 3] != 0)
    {
        printf("The chosen cell is occupied. Please input again:\n");
        scanf("%d", &input);
    }
    gameBoard[2 - (input - 1) / 3][(input - 1) % 3] = 1;
}

/* Choose a game board and place a cross according to the user inputs.
   The user input may not be valid, but you can assume that it must be an integer. */
void placeCrossByHumanPlayer(int gameBoard1[3][3], int gameBoard2[3][3])
{
    printf("Choose the game board:\n");
    int board;
    scanf("%d", &board);
    while (board != 1 && board != 2)
    {
        printf("Input out of range. Please input again:\n");
        scanf("%d", &board);
    }
    while (isGameBoardDead(board == 1 ? gameBoard1 : gameBoard2) == 1)
    {
        printf("The chosen game board is dead. Please input again:\n");
        scanf("%d", &board);
    }
    updateGameBoard(board == 1 ? gameBoard1 : gameBoard2);
}

/* Return the number of crosses on the specified game board. */
int countNumOfCrosses(int gameBoard[3][3])
{
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (gameBoard[i][j] == 1)
            {
                count++;
            }
        }
    }
    return count;
}

/* Determine the next move of the computer player and update the corresponding game board accordingly.
   You are required to exactly follow the strategy mentioned in the project specification.
   IMPORTANT: Using other strategies will result in mark deduction. */
void placeCrossByComputerPlayer(int gameBoard1[3][3], int gameBoard2[3][3])
{
    int board = 0;
    if (isGameBoardDead(gameBoard1) == 0 && isGameBoardDead(gameBoard2) == 0)
    {
        board = countNumOfCrosses(gameBoard1) > countNumOfCrosses(gameBoard2) ? 2 : 1;
        printf("Choose the game board:\n%d\n", board);
        if (board == 1)
        {
            for (int i = 1; i <= 9; i++)
            {
                if (gameBoard1[2 - (i - 1) / 3][(i - 1) % 3] == 0)
                {
                    printf("Choose the cell:\n%d\n", i);
                    gameBoard1[2 - (i - 1) / 3][(i - 1) % 3] = 1;
                    break;
                }
            }
        }
        else
        {
            for (int i = 9; i >= 1; i--)
            {
                if (gameBoard2[2 - (i - 1) / 3][(i - 1) % 3] == 0)
                {
                    printf("Choose the cell:\n%d\n", i);
                    gameBoard2[2 - (i - 1) / 3][(i - 1) % 3] = 1;
                    break;
                }
            }
        }
    }
    else
    {
        if (isGameBoardDead(gameBoard1) == 1)
        {
            printf("Choose the game board:\n2\n");
            board = 2;

            // make the largest move that will not make the game board dead
            // if not possible take the largest move

            // copy of the game board
            int gameBoard[3][3] = {0};
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    gameBoard[i][j] = board == 1 ? gameBoard1[i][j] : gameBoard2[i][j];
                }
            }
            // find the largest move that will not make the game board dead
            for (int i = 9; i >= 1; i--)
            {
                if (gameBoard[2 - (i - 1) / 3][(i - 1) % 3] == 0)
                {
                    gameBoard[2 - (i - 1) / 3][(i - 1) % 3] = 1;
                    if (isGameBoardDead(gameBoard) == 0)
                    {
                        printf("Choose the cell:\n%d\n", i);
                        gameBoard2[2 - (i - 1) / 3][(i - 1) % 3] = 1;
                        break;
                    }
                    else
                    {
                        gameBoard[2 - (i - 1) / 3][(i - 1) % 3] = 0;
                    }
                }
            }
        }
        else
        {
            printf("Choose the game board:\n1\n");
            board = 1;

            // make the smallest move that will not make the game board dead

            // copy of the game board
            int gameBoard[3][3] = {0};
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    gameBoard[i][j] = board == 1 ? gameBoard1[i][j] : gameBoard2[i][j];
                }
            }
            // find the smallest move that will not make the game board dead
            for (int i = 1; i <= 9; i++)
            {
                if (gameBoard[2 - (i - 1) / 3][(i - 1) % 3] == 0)
                {
                    gameBoard[2 - (i - 1) / 3][(i - 1) % 3] = 1;
                    if (isGameBoardDead(gameBoard) == 0)
                    {
                        printf("Choose the cell:\n%d\n", i);
                        if (board == 1)
                        {
                            gameBoard1[2 - (i - 1) / 3][(i - 1) % 3] = 1;
                        }
                        else
                        {
                            gameBoard2[2 - (i - 1) / 3][(i - 1) % 3] = 1;
                        }
                        break;
                    }
                    else
                    {
                        gameBoard[2 - (i - 1) / 3][(i - 1) % 3] = 0;
                    }
                }
            }
        }
    }
}

/* The main function */
int main()
{
    /* Local variables */
    int gameBoard1[3][3];  // Represent Game Board 1
    int gameBoard2[3][3];  // Represent Game Board 2
    int currentPlayer;     // 1: Player 1             2: Player 2
    int gameEnd;           // 0: The game continues   1: The game ends
    int numOfHumanPlayers; // 1 or 2

    /* Initialize the local variables */
    initGameBoard(gameBoard1);
    initGameBoard(gameBoard2);
    currentPlayer = 1;
    gameEnd = 0;
    printf("Enter the number of human players [1-2]:\n");
    scanf("%d", &numOfHumanPlayers); // You can assume that the user input must be valid here

    /* Uncomment the following statements to test whether the printTwoGameBoards() and the placeCrossByHumanPlayer() functions are implemented correctly.
       You can add more if you wish.
       After testing, you can delete them or move them elsewhere. */
    // printTwoGameBoards(gameBoard1, gameBoard2);
    // printf("# Player 1's turn #\n");
    // placeCrossByHumanPlayer(gameBoard1, gameBoard2);
    // printTwoGameBoards(gameBoard1, gameBoard2);
    // printf("# Player 2's turn #\n");
    // placeCrossByHumanPlayer(gameBoard1, gameBoard2);
    // printTwoGameBoards(gameBoard1, gameBoard2);

    /* Game start
       If there are two human players, they are Player 1 and Player 2
       If there is only one human player, he/she is Player 1 and another player is the computer
       For both cases, Player 1 moves first
       Hint: use a while loop */

    while (gameEnd == 0)
    {
        printTwoGameBoards(gameBoard1, gameBoard2);
        if (isGameBoardDead(gameBoard1) == 1 && isGameBoardDead(gameBoard2) == 1)
        {
            gameEnd = 1;
            if (numOfHumanPlayers == 1)
            {
                if (currentPlayer == 1)
                {
                    printf("Congratulations! Player 1 wins!\n");
                }
                else
                {
                    printf("Computer wins!\n");
                }
            }
            else
            {
                if (currentPlayer == 1)
                {
                    printf("Congratulations! Player 1 wins!\n");
                }
                else
                {
                    printf("Congratulations! Player 2 wins!\n");
                }
            }
            break;
        }
        if (numOfHumanPlayers == 1)
        {
            if (currentPlayer == 1)
            {
                printf("# Player 1's turn #\n");
                placeCrossByHumanPlayer(gameBoard1, gameBoard2);
                currentPlayer = 2;
            }
            else
            {
                printf("# Computer's turn #\n");
                placeCrossByComputerPlayer(gameBoard1, gameBoard2);
                currentPlayer = 1;
            }
        }
        else
        {
            if (currentPlayer == 1)
            {
                printf("# Player 1's turn #\n");
                placeCrossByHumanPlayer(gameBoard1, gameBoard2);
                currentPlayer = 2;
            }
            else
            {
                printf("# Player 2's turn #\n");
                placeCrossByHumanPlayer(gameBoard1, gameBoard2);
                currentPlayer = 1;
            }
        }
    }

    return 0;
}