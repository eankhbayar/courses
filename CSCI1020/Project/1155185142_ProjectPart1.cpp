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
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				board[i][j] = i*3+j+1;
			}
		}		
	}

	/* Display the game board
	   In Part 1, you are required to follow the output format in the sample run
	   You are welcome to design and implement a better one in Part 2 */
	void display() {
		for(int i=0;i<3;i++){
			cout<<"|";
			for(int j=0;j<3;j++){
				if(board[i][j] == -1){
					cout<<"S";
				}else if(board[i][j] == -2){
					cout<<"O";
				}else{
					cout<<board[i][j];
				}
				cout<<"|";
			}
			cout<<"\n";
		}
	}


	/* If the specified position is empty, place the mark and return true
	   If the specified position has an existing mark, simply return false
	   Hint: the return value is useful for the computer's naive strategy in Part 1 */
	bool placeMark(int position, char mark) {
		int row = (position-1)/3;
		int col = (position-1)%3;
		if(board[row][col] == position){
			if(mark == 'S'){
				board[row][col] = -1;
			}
			if(mark == 'O'){
				board[row][col] = -2;
			}
			return true;
		}else{
			return false;
		}
	}

	/* Return true if there is a winner; otherwise return false
	   The winning message is not printed by this function
	   Hint: The winner is the current player who just placed the mark */
	bool hasWinner() {
		for(int i=0;i<3;i++){
			if(board[i][0] == -1 && board[i][1] == -2 && board[i][2] == -1){
				return true;
			}
		}
		for(int i=0;i<3;i++){
			if(board[0][i] == -1 && board[1][i] == -2 && board[2][i] == -1){
				return true;
			}
		}
		if(board[0][0] == -1 && board[1][1] == -2 && board[2][2] == -1){
			return true;
		}
		if(board[0][2] == -1 && board[1][1] == -2 && board[2][0] == -1){
			return true;
		}
		return false;
	}

	/* Return true if the game board is full; otherwise return false
	   The draw game message is not printed by this function */
	bool isFull() {
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(board[i][j] != -1 && board[i][j] != -2){
					return false;
				}
			}
		}
		return true;
	}

	/* no other constructors nor member functions are allowed */
};



/* TODO: Define classes for the players here */

class Player {
private:
	string player_type;
	string player_name;
public:
	Player(string player_type, string player_name){
		this->player_type = player_type;
		this->player_name = player_name;
	}
	string getPlayerType(){
		return player_type;
	}
	string getPlayerName(){
		return player_name;
	}
	void setPosition(GameBoard *board){
		int move;
		char mark;
		if(this->player_type == "human"){
			cout<<"Input position:\n";
			cin>>move;
			cout<<"Input mark:\n";
			cin>>mark;
			board->placeMark(move, mark);
		}else{
			for(int i=1;i<=9;i++){
				if(i%2==1){
					if(board->placeMark(i, 'S')){
						move = i;
						mark = 'S';
						break;
					}
				}else{
					if(board->placeMark(i, 'O')){
						move = i;
						mark = 'O';
						break;
					}
				}
			}
		}

	}
};

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
	GameBoard board;
	int numOfPlayers;
	Player players[2] = {Player("human", "Player 1"), Player("human", "Player 2")};
	int turn;
public:
	/* Constructor: create the player objects and the board object
	   If there is only one human player, he/she is named "Player 1" and the computer player is named "Computer"
	   If there are two human players, they are named "Player 1" and "Player 2" */
	SOSGame(int numOfPlayers) : board(), numOfPlayers(), turn(0) {
		this->numOfPlayers = numOfPlayers;
		this->board = GameBoard();
		numOfPlayers == 1 ? this->players[1] = Player("computer", "Computer") : this->players[1] = Player("human", "Player 2");
		this->turn = 0;
	}

	/* Called once in main()
	   Player 1 moves first */
	void start() {
		while(true){
			board.display();
			cout<<"#"<<this->players[this->turn].getPlayerName()<<"'s turn#\n";
			players[this->turn].setPosition(&board);
			if(board.hasWinner()){
				board.display();
				cout<<this->players[this->turn].getPlayerName()<<" wins!\n";
				break;
			}
			if(board.isFull()){
				board.display();
				cout<<"Draw game!\n";
				break;
			}
			this->turn = (this->turn+1)%2;
		}
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