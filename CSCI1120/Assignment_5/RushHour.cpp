// Name:       Ankhbayar Enkhtaivan
// Student ID: 1155185142
// Email:      1155185142@link.cuhk.edu.hk

#include "RushHour.h"
#include <iostream>
using namespace std;

RushHour::RushHour(string g[]) {
    grid[0] = "########";
    grid[7] = "########";
    for (int i=0; i<6; i++){
        grid[i+1] = g[i];
    }
    totalSteps = 0;
}

bool RushHour::locateCar(int car, int &row, int &col) const {
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            if(grid[i+1][j+1] == car + '0'){
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

int RushHour::moveCar(int car, int step){

    if(step == 0) return 1;

    int row, col;
    if(locateCar(car, row, col) == false){
        return 1;
    }
    row++;
    col++;

    char horizontal = 'h';
    if(grid[row][col] == grid[row][col+1]){
        horizontal = 'h';
    }
    else{
        horizontal = 'v';
    }

    int length = 0;
    if(horizontal == 'h'){
        for(int i=0;i<=6;i++){
            if(grid[row][col] == grid[row][col+1+i]){
                length++;
            }
            else{
                break;
            }
        }
    }else{
        for(int i=0;i<=6;i++){
            if(grid[row][col] == grid[row+1+i][col]){
                length++;
            }
            else{
                break;
            }
        }
    }

    if(horizontal == 'h'){
        if(step > 0){
            for(int i=1;i<=step;i++){
                if(grid[row][col+length+i] != '.'){
                    return 2;
                }
            }
            for(int i=1;i<=step;i++){
                grid[row][col+length+i] = grid[row][col+length+i-1];
                grid[row][col+i-1] = '.';
            }
            totalSteps += step;
        }else{
            for(int i=1;i<=-step;i++){
                if(grid[row][col-i] != '.'){
                    return 2;
                }
            }
            for(int i=1;i<=-step;i++){
                grid[row][col - i] = grid[row][col - i + 1];
                grid[row][col + length - i + 1] = '.';
            }
            totalSteps -= step;
        }
    }else{
        if(step > 0){
            for(int i=1;i<=step;i++){
                if(grid[row+length+i][col] != '.'){
                    return 2;
                }
            }
            for(int i=1;i<=step;i++){
                grid[row+length+i][col] = grid[row+length+i-1][col];
                grid[row+i-1][col] = '.';
            }
            totalSteps += step;
        }else{
            for(int i=1;i<=-step;i++){
                if(grid[row-i][col] != '.'){
                    return 2;
                }
            }
            for(int i=1;i<=-step;i++){
                grid[row - i][col] = grid[row - i + 1][col];
                grid[row + length - i + 1][col] = '.';
            }
            totalSteps -= step;
        }
    }
    return 0;
}

bool RushHour::isSolved() const {
    for(int i=0; i<6;i++){
        if(grid[i][7] == '0'){
            return true;
        }
    }
    return false;
}

int RushHour::getTotalSteps() const {
    return totalSteps;
}

void RushHour::print() const {
    for(int i=0; i<8; i++){
        cout << grid[i] << endl;
    }
    cout << "Steps: " << getTotalSteps() << endl;
}