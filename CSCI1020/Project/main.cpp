/***********************************************************************
CSCI1020 Hands-on Introduction to C++

I declare that the source code here submitted is original except for source
material explicitly acknowledged. I also acknowledge that I am aware of
University policy and regulations on honesty in academic work, and of the
disciplinary guidelines and procedures applicable to breaches of such
policy and regulations, as contained in the following University website:
https://www.cuhk.edu.hk/policy/academichonesty/

Student Name: Ankhbayar Enkhtaivan
Student ID: 1155185142
Date: 05/04/2023
***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

/* Represent the game board */
class GameBoard {
private:
	int board[3][3];
	/* no other member variables are allowed */

public:
	/* Constructor: initialize the game board */
	GameBoard() {
		
		// TODO: Complete this part
		
	}

	/* Display the game board
	   In Part 1, you are required to follow the output format in the sample run
	   You are welcome to design and implement a better one in Part 2 */
	void display() {
		
		// TODO: Complete this part
		
	}


	/* If the specified position is empty, place the mark and return true
	   If the specified position has an existing mark, simply return false
	   Hint: the return value is useful for the computer's naive strategy in Part 1 */
	bool placeMark(int position, char mark) {
		
		// TODO: Complete this part
		
	}

	/* Return true if there is a winner; otherwise return false
	   The winning message is not printed by this function
	   Hint: The winner is the current player who just placed the mark */
	bool hasWinner() {
		
		// TODO: Complete this part
	
	}

	/* Return true if the game board is full; otherwise return false
	   The draw game message is not printed by this function */
	bool isFull() {
		
		// TODO: Complete this part
	
	}

	/* no other constructors nor member functions are allowed */
};



/* TODO: Define classes for the players here */

/* In Part 1, you can assume that the user input must be valid
   (i.e, an empty square between 1 and 9 for the position, and 'S' or 'O' for the mark)
   You are welcome to handle invalid inputs in Part 2 */

/* In Part 1, the computer move is the first empty square scanning from 1 to 9
   If the position is odd, the mark will be 'S'; otherwise, the mark will be 'O'
   You are welcome to design and implement better strategies in Part 2.
   Hint: call placeMark() of the GameBoard object */



/* Represent the game */
class SOSGame {
private:
	/* Declare member variables */
	// TODO: Complete this part

public:
	/* Constructor: create the player objects and the board object
	   If there is only one human player, he/she is named "Player 1" and the computer player is named "Computer"
	   If there are two human players, they are named "Player 1" and "Player 2" */
	SOSGame(int numOfPlayers) {
		
		// TODO: Complete this part
	
	}

	/* Called once in main()
	   Player 1 moves first */
	void start() {
		
		// TODO: Complete this part
	
	}

	/* no other constructors nor member functions are allowed */
};

/* The main function, no modification is allowed */
int main() {
	int numOfPlayers;
	cout << "How many players (1 or 2)?" << endl;
	cin >> numOfPlayers;
	SOSGame game(numOfPlayers);
	game.start();
	return 0;
}