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
Date: 30/04/2023
***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

/* Represent the game board */
class GameBoard {
private:
	// init board for variable sizing
	int board[10][10];
	int size;
	/* no other member variables are allowed */

public:
	/* Constructor: initialize the game board */
	GameBoard(int size) {
		this->size = size;

		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				board[i][j] = i*size+j+1;
			}
		}		
	}

	/* Display the game board
	   In Part 1, you are required to follow the output format in the sample run
	   You are welcome to design and implement a better one in Part 2 */
	void display() {
		for(int i=0;i<size;i++){
			cout<<"|";
			for(int j=0;j<size;j++){
				if(board[i][j] == -1){
					if(size * size > 10){
						cout<<" ";
					}
					cout<<"S";
				}else if(board[i][j] == -2){
					if(size * size > 10){
						cout<<" ";
					}
					cout<<"O";
				}else{
					// print number with 2 spaces
					if(board[i][j] < 10 && size * size > 10){
						cout<<" ";
					}
					cout<<board[i][j];
				}
				cout<<"|";
			}
			cout<<"\n";
		}
	}

	int getSize(){
		return size;
	}

	char getMark(int row, int col){
		if(board[row][col] == -1){
			return 'S';
		}else if(board[row][col] == -2){
			return 'O';
		}else{
			return ' ';
		}
	}

	/* If the specified position is empty, place the mark and return true
	   If the specified position has an existing mark, simply return false
	   Hint: the return value is useful for the computer's naive strategy in Part 1 */
	bool placeMark(int position, char mark) {
		int row = (position-1)/size;
		int col = (position-1)%size;
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

	bool removeMark(int position){
		int row = (position-1)/size;
		int col = (position-1)%size;
		if(board[row][col] == -1 || board[row][col] == -2){
			board[row][col] = position;
			return true;
		}else{
			return false;
		}
	}

	/* Return true if there is a winner; otherwise return false
	   The winning message is not printed by this function
	   Hint: The winner is the current player who just placed the mark */
	bool hasWinner() {
		for(int i=0;i<size;i++){
			if(board[i][0] == -1 && board[i][1] == -2 && board[i][2] == -1){
				return true;
			}
		}
		for(int i=0;i<size;i++){
			if(board[0][i] == -1 && board[1][i] == -2 && board[2][i] == -1){
				return true;
			}
		}
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				if(board[i][j] == -1 && board[i+1][j+1] == -2 && board[i+2][j+2] == -1){
					return true;
				}
				if(i>2 && j<size-2){
					if(board[i][j] == -1 && board[i-1][j+1] == -2 && board[i-2][j+2] == -1){
						return true;
					}
				}
			}
		}
		return false;
	}

	/* Return true if the game board is full; otherwise return false
	   The draw game message is not printed by this function */
	bool isFull() {
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				if(board[i][j] != -1 && board[i][j] != -2){
					return false;
				}
			}
		}
		return true;
	}

	int score(){
		int score = 0;
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				// check for SO
				if(board[i][j] == -1 && board[i][j+1] == -2 && board[i][j+2] != -1 && board[i][j+2] != -2){
					score-=1e5;
				}else{
					score++;
				}
				if(board[i][j] == -1 && board[i+1][j] == -2 && board[i+2][j] != -1 && board[i+1][j] != -2){
					score-=1e5;
				}else{
					score++;
				}
				if(board[i][j] == -1 && board[i+1][j+1] == -2 && board[i+2][j+2] != -1 && board[i+2][j+2] != -2){
					score-=1e5;
				}else{
					score++;
				}
				if(board[i][j] == -1 && board[i][j+2] == -1 && board[i][j+1] != -1 && board[i][j+1] != -2){
					score-=1e5;
				}else{
					score++;
				}
				if(board[i][j] == -1 && board[i+2][j] == -1 && board[i+1][j] != -1 && board[i+1][j] != -2){
					score-=1e5;
				}else{
					score++;
				}
				if(board[i][j] == -1 && board[i+2][j+2] == -1 && board[i+1][j+1] != -1 && board[i+1][j+1] != -2){
					score-=1e5;
				}else{
					score++;
				}
			}			
		}
		return score;
	}

	/* no other constructors nor member functions are allowed */
};

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
		if(this->player_type == "human"){
			int move;
			char mark;
			cout<<"Input position:\n";
			cin>>move;
			cout<<"Input mark:\n";
			cin>>mark;
			int validMove = board->placeMark(move, mark);
			while(validMove == 0){
				cout<<"Invalid move. Input position:\n";
				cin>>move;
				cout<<"Input mark:\n";
				cin>>mark;
				validMove = board->placeMark(move, mark);
			}
		}else{
			int move;
			char mark;
			int bestScore = -1e9;
			int bestRow = -1;
			int bestCol = -1;
			char bestMark = ' ';
			int size = board->getSize();
			int tmp = 0;
			for(int i=0;i<size;i++){
				for(int j=0;j<size;j++){
					if(board->getMark(i,j) == ' '){
						if(board->getMark(i-1,j) == 'S' && board->getMark(i+1,j) == 'S'){
							bestRow = i;
							bestCol = j;
							bestMark = 'O';
							tmp = 1;
							break;
						}
						if(board->getMark(i,j-1) == 'S' && board->getMark(i,j+1) == 'S'){
							bestRow = i;
							bestCol = j;
							tmp = 1;
							bestMark = 'O';
							break;
						}
						if(board->getMark(i-1,j-1) == 'S' && board->getMark(i+1,j+1) == 'S'){
							bestRow = i;
							bestCol = j;
							tmp = 1;
							bestMark = 'O';
							break;
						}
						if(board->getMark(i-1,j+1) == 'S' && board->getMark(i+1,j-1) == 'S'){
							bestRow = i;
							bestCol = j;
							tmp = 1;
							bestMark = 'O';
							break;
						}
						if(board->getMark(i-1,j) == 'O' && board->getMark(i-2,j) == 'S'){
							bestRow = i;
							bestCol = j;
							tmp = 1;
							bestMark = 'S';
							break;
						}
						if(board->getMark(i,j-1) == 'O' && board->getMark(i,j-2) == 'S'){
							bestRow = i;
							bestCol = j;
							tmp = 1;
							bestMark = 'S';
							break;
						}
						if(board->getMark(i-1,j-1) == 'O' && board->getMark(i-2,j-2) == 'S'){
							bestRow = i;
							bestCol = j;
							tmp = 1;
							bestMark = 'S';
							break;
						}
						if(board->getMark(i-1,j+1) == 'O' && board->getMark(i-2,j+2) == 'S'){
							bestRow = i;
							bestCol = j;
							tmp = 1;
							bestMark = 'S';
							break;
						}
					}
				}
			}

			if(tmp == 0){
				for(int i=0;i<size;i++){
				for(int j=0;j<size;j++){
					if(board->getMark(i,j) == ' '){
						// try 'S' first
						board->placeMark(i*size+j+1, 'S');
						int score = board->score();
						if(score > bestScore){
							bestScore = score;
							bestRow = i;
							bestCol = j;
							bestMark = 'S';
						}
						board->removeMark(i*size+j+1);
						board->placeMark(i*size+j+1, 'O');
						score = board->score();
						if(score > bestScore){
							bestScore = score;
							bestRow = i;
							bestCol = j;
							bestMark = 'O';
						}
						board->removeMark(i*size+j+1);
					}
				}
				}
			}
			cout<<"Input position:\n";
			cout<<bestRow*board->getSize()+bestCol+1<<endl;
			cout<<"Input mark:\n";
			cout<<bestMark<<endl;
			board->placeMark(bestRow*board->getSize()+bestCol+1, bestMark);
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
	GameBoard board = GameBoard(3);
	int numOfPlayers;
	Player players[2]= {Player("human", "Player 1"), Player("human", "Player 2")};
	int turn;
public:
	/* Constructor: create the player objects and the board object
	   If there is only one human player, he/she is named "Player 1" and the computer player is named "Computer"
	   If there are two human players, they are named "Player 1" and "Player 2" */
	SOSGame(int numOfPlayers, int size){
		this->numOfPlayers = numOfPlayers;
		this->board = GameBoard(size);
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
	int size;
	cout << "What is the size of the board? (1 to 9)" << endl;
	cin >> size;
	SOSGame game(numOfPlayers, size);
	game.start();
	return 0;
}