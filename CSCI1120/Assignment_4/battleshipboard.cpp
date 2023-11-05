// Name:       Ankhbayar Enkhtaivan
// Student ID: 1155185142
// Email:      1155185142@link.cuhk.edu.hk

#include <iostream>
#include <iomanip>
#include <cctype>
#include "battleshipboard.h"
/* You may add extra standard library headers if you see fit */

using namespace std;

// Return a 5-letter string showing which ships of the specified fleet have sunk
string fleetStatus(Fleet fleet) {
    string status = "";

    for(int i=0;i<5;i++){
        if(fleet.alive[i] == 0){
            status += HIT;
        }else{
            status += SHIP_TYPE[i][0];
        }
    }

    return status;
}

// Print the status string of each fleet
void printStatus(Fleet fleet1, Fleet fleet2) {
    cout << setw(N*2 + 2) << left;
    cout << fleet1.name + " Fleet: " + fleetStatus(fleet1) << "  ";
    cout << setw(N*2 + 2) << left;
    cout << fleet2.name + " Fleet: " + fleetStatus(fleet2) << endl;
}

// Print the user and computer game boards side by side
void printBoards(char board1[][N], char board2[][N], bool gameMode) {
    cout << setw(N*2 + 2) << left << "Enemy Ocean" << "  "
         << setw(N*2 + 2) << left << "Your Ocean" << endl << right;
    
    // print column headers for both game boards
    for (int i = 0; i < 2; i++) {
        cout << string(2 + i*2, ' ');
        for (int j = 0; j < N; j++)
            cout << setw(2) << char('A' + j);
    }
    cout << endl;

    // print row indexes and board content for both game boards
    
    for (int i = 0; i < N;i++){
        cout<< setw(2) << i + 1;

        if(gameMode==true){
            for (int j=0;j<N;j++){
                if(board1[i][j] == HIT){
                    cout << setw(2) << HIT;
                }else if(board1[i][j] == MISS){
                    cout << setw(2) << MISS;
                }else{
                    cout << setw(2) << BLANK;
                }
            }
        }else{
            for(int j=0;j<N;j++){
                cout << setw(2) << board1[i][j];
            }
        }
        cout<<setw(2)<<" ";        
        cout<< setw(2) << i + 1;
        // cout << string(1 + k * 2, ' ');
        for (int j=0;j<N;j++){
            cout << setw(2) << board2[i][j];
        }
        cout<<endl;
    }

}

// Check if the specified location (y, x) is within the board
bool isValidCell(int y, int x) {
    return y >= 0 && y < N && x >= 0 && x < N;
}

// Check if a shoot location (y, x) is valid
bool isValidShoot(char board[][N], int y, int x) {
    return isValidCell(y, x) && board[y][x] != HIT && board[y][x] != MISS;
}

// Convert ship letter to its index in the ship type array
int indexOf(char ship) {
    for (int i = 0; i < 5; i++)
        if (SHIP_TYPE[i][0] == ship)
            return i;
    return -1;
}

// Carry out a shot on the specified board at location (y, x)
bool shoot(char board[][N], int y, int x, Fleet* fleet) {
    if(board[y][x] == BLANK){
        board[y][x] = MISS;
        return false;
    }else{
        int index = indexOf(board[y][x]);
        board[y][x] = HIT;
        fleet->alive[index] -= 1;
        if(fleet->alive[index] == 0){
            cout<<fleet->name<<"'s "<<SHIP_TYPE[index]<<" sunk!"<<endl;
        }
        return true;
    }
}

// Get location (y, x) from the user via console input
bool getCellFromConsole(int& y, int& x) {
    char col; int row;
    cin >> col >> row;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    
    col = toupper(col);
    if (col < 'A' || col > 'A' + N - 1 || row < 1 || row > N) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }

    y = row - 1; x = col - 'A';
    
    return true;
}

// Get a random location (y, x) within board size
void getRandomCell(int& y, int& x) {
    y = rand() % N;
    x = rand() % N;
}

// Prompt the user for shoot location (y, x)
bool getHumanMove(int& y, int& x) {
    cout << "Enter attack location: ";
    return getCellFromConsole(y, x);
}

// Get shoot location (y, x) by the computer player's strategy
bool getComputerMove(char board[][N], int& y, int& x) {
    // try to shoot neighborhood of an existing hit first
    const int TRIALS = 1000;
    int dy[] = { -1,  0,  1,  0 };  // deltas for getting the cell at 
    int dx[] = {  0,  1,  0, -1 };  // North, East, South, West around (y, x)
    for (int t = 0; t < TRIALS; t++) {
        int i, j;
        getRandomCell(i, j);
        if (board[i][j] == HIT) {
            int st = rand() % 4;
            for (int k = 0; k < 4; k++) {
                int r = (st + k) % 4;  // random start in dy, dx
                if (isValidCell(i + dy[r], j + dx[r]) && 
                    board[i + dy[r]][j + dx[r]] != HIT && 
                    board[i + dy[r]][j + dx[r]] != MISS) {
                    y = i + dy[r]; x = j + dx[r];
                    return true;
                }
            }
        }
    }

    // shoot at a random location
    getRandomCell(y, x);
    return true;
}

// Place ship on board in specified orientation (vertical or horizontal)
bool placeShip(char board[][N], int y, int x, char ship, bool vertical = false) {
    int len = SHIP_SIZE[indexOf(ship)];
    if (vertical == true) {
        if (y + len > N) return false;
        for (int i = y; i < y + len; i++)
            if (board[i][x] != BLANK) return false;
        for (int i = y; i < y + len; i++)
            board[i][x] = ship;
    }
    else {
        if (x + len > N) return false;
        for (int j = x; j < x + len; j++)
            if (board[y][j] != BLANK) return false;
        for (int j = x; j < x + len; j++)
            board[y][j] = ship;
    }
    return true;
}

// Randomly place all ships on board
void randomlyPlaceShips(char board[][N]) {
    for (int k = 0; k < 5; k++) {
        char ship = SHIP_TYPE[k][0];
        while (true) {
            int y, x;
            bool vertical = bool(rand() % 2);
            getRandomCell(y, x);
            if (placeShip(board, y, x, ship, vertical))
                break;
        }
    }
}

// Manually place all ships on board
void manuallyPlaceShips(char board[][N]) {
    for (int k = 0;k<5;k++){
        while(true){
            cout<<"Enter h/v and location for " << SHIP_TYPE[k] <<": ";
            char hv;
            cin>>hv;
            int y,x;
            bool ok = getCellFromConsole(y,x);

            if(ok){
                if(hv == 'h'){
                    if(placeShip(board,y,x,SHIP_TYPE[k][0],false)){
                        break;
                    }else{
                        cout<<"Invalid ship location!"<<endl;
                    }
                }else if(hv == 'v'){
                    if(placeShip(board,y,x,SHIP_TYPE[k][0],true)){
                        break;
                    }else{
                        cout<<"Invalid ship location!"<<endl;
                    }
                }else{
                    cout<<"Invalid ship location!"<<endl;
                }
            }else{
                cout<<"Invalid ship location!"<<endl;
            }
        }
    }
}