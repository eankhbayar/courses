// Name:       Ankhbayar Enkhtaivan
// Student ID: 1155185142
// Email:      1155185142@link.cuhk.edu.hk

#include <iostream>
#include "shisimaboard.h"

using namespace std;
int main(){
    int board = 102102102;
    int turn = 1;
    while(true){
        printBoard(board);
        if(formLine(board) == 1){
            cout << "Player 1 wins!" << endl;
            break;
        }
        else if(formLine(board) == 2){
            cout << "Player 2 wins!" << endl;
            break;
        }

        int pos1, pos2;
        cout << "Player " << turn << " (from to): ";
        cin >> pos1 >> pos2;

        while(movePiece(board, pos1, pos2, turn) == false){
            cout << "Invalid. Try again!" << endl;
            cout << "Player " << turn << " (from to): ";
            cin >> pos1 >> pos2;
        }
        if (turn == 1) turn = 2;
        else turn = 1;
    }
}