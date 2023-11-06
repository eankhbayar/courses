// Name:       Ankhbayar Enkhtaivan
// Student ID: 1155185142
// Email:      1155185142@link.cuhk.edu.hk

#include "RushHour.h"
#include <iostream>
using namespace std;

int main(){
    string grid[6];

    cout << "Enter Initial Grid: ";
    for(int i=0; i<6; i++){
        cin >> grid[i];
    }

    RushHour game(grid);
    bool gameOver = false;

    while(gameOver == false){
        game.print();
        cout << "Move a car: ";
        int car, step;
        cin >> car >> step;
        int moveResult = game.moveCar(car, step);
        while(moveResult != 0){
            if(moveResult == 1){
                cout << "Invalid car or step! Try again." << endl;
            }else{
                cout << "Hit! Try again." << endl;
            }
            cout << "Move a car: ";
            cin >> car >> step;
            moveResult = game.moveCar(car, step);
        }

        gameOver = game.isSolved();
        int totalSteps = game.getTotalSteps();

        if(totalSteps >= 100){
            cout << "Oops! You could not solve in 100 steps." << endl;
            return 0;
        }
    }

    cout << "Congratulations! You solved it in " << game.getTotalSteps() << " steps." << endl;

}