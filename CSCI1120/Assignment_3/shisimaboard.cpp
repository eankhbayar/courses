// Name:       Ankhbayar Enkhtaivan
// Student ID: 1155185142
// Email:      1155185142@link.cuhk.edu.hk

#include "shisimaboard.h"
#include <iostream>
using namespace std;

/* Returns the state of position pos of the game board. */
int boardState(int board, int pos) {
    // TODO: Add a return statement in order to compile
    for(int i=1; i<10 - pos;i++){
        board/=10;
    }
    return board%10;
}

/* Prints the board to the screen. DO NOT MODIFY! */
void printBoard(int board) {
    cout << "  " << boardState(board, 1) << "-" << boardState(board, 2) << "-" << boardState(board, 3) << endl;
    cout << " / \\|/ \\" << endl;
    cout << boardState(board, 4) << "---" << boardState(board, 5) << "---" << boardState(board, 6) << endl;
    cout << " \\ /|\\ /" << endl;
    cout << "  " << boardState(board, 7) << "-" << boardState(board, 8) << "-" << boardState(board, 9) << endl;
}

/* Performs the task of player p moving a piece from position pos1 to position
   pos2 of board. */
bool movePiece(int &board, int pos1, int pos2, int p) {
    // TODO: Add a return statement in order to compile
    if(pos1 < 1 || pos1 > 9 || pos2 < 1 || pos2 > 9) return false;
    if(boardState(board, pos1) != p) return false;
    if(boardState(board, pos2) != 0) return false;

    // check if pos1, pos2 are adjacent
    if(pos1 == 1){
        if(pos2 != 2 && pos2 != 4 && pos2 != 5) return false;
    }
    else if(pos1 == 2){
        if(pos2 != 1 && pos2 != 3 && pos2 != 5) return false;
    }
    else if(pos1 == 3){
        if(pos2 != 2 && pos2 != 5 && pos2 != 6) return false;
    }
    else if(pos1 == 4){
        if(pos2 != 1 && pos2 != 5 && pos2 != 7) return false;
    }
    else if(pos1 == 5){
        if(pos2 != 1 && pos2 != 2 && pos2 != 3 && pos2 != 4 && pos2 != 6 && pos2 != 7 && pos2 != 8 && pos2 != 9) return false;
    }
    else if(pos1 == 6){
        if(pos2 != 3 && pos2 != 5 && pos2 != 9) return false;
    }
    else if(pos1 == 7){
        if(pos2 != 4 && pos2 != 5 && pos2 != 8) return false;
    }
    else if(pos1 == 8){
        if(pos2 != 5 && pos2 != 7 && pos2 != 9) return false;
    }
    else if(pos1 == 9){
        if(pos2 != 5 && pos2 != 6 && pos2 != 8) return false;
    }

    // move piece
    int move_1 = 1;
    int move_2 = 1;

    for(int i=1; i<10 - pos1; i++){
        move_1 *= 10;
    }
    for(int i=1; i<10 - pos2; i++){
        move_2 *= 10;
    }

    board -= move_1*p;
    board += move_2*p;

    return true;
}

/* Checks if any player has formed a line of three pieces crossing the middle
   of the board. */
int formLine(int board) {
    // TODO: Add a return statement in order to compile
    if(board/1000%1000 == 111) return 1;
    if(board/1000%1000 == 222) return 2;

    if(boardState(board, 1) == boardState(board, 5) && boardState(board, 5) == boardState(board, 9)){
        if(boardState(board, 1) == 1) return 1;
        if(boardState(board, 1) == 2) return 2;
    }
    if(boardState(board, 3) == boardState(board, 5) && boardState(board, 5) == boardState(board, 7)){
        if(boardState(board, 3) == 1) return 1;
        if(boardState(board, 3) == 2) return 2;
    }
    return 0;
}

/* You may write a main() in this file for debugging purpose, but it must be
   removed or commented in your submitted version. */