//
//  game_of_life.cpp
//  game_of_life
//
//  Created by Dario Caric on 14.04.2024..
//

#include "game_of_life.hpp"
#include <time.h>

/**
 Sets initial game with 25% cells live
 */
game_of_life::game_of_life() {
    srand(time(NULL));
    
    // set all to false
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            _generation[i][j] = false;
            _next_generation[i][j] = false;
        }
    }
    
    // generate array of ROWS * COLS where 25% elements will be true and the rest false
    int totalTrueCells = ROWS * COLS * 0.25;
    cout << "Total true cells: " << totalTrueCells << endl;
    
    // generate ROWS * COLS *0.25 numbers between 1 and ROWS * COLS
    for (int i = 0; i < totalTrueCells; i++) {
        int random = rand() % (ROWS * COLS);
        int row = random / COLS;
        int col = random % COLS;
        _generation[row][col] = true;
    }
    
    // print the array
    /*
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << _generation[i][j] << " ";
        }
        cout << endl;
    }
     */

}


/**
 Runs next game iterraion
 */
void game_of_life::next_generation() {
    // for each cell
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            
            // count the number of live neighbours
            int liveNeighbours = 0;
            for (int k = i - 1; k <= i + 1; k++) {
                for (int l = j - 1; l <= j + 1; l++) {
                    if (k >= 0 && k < ROWS && l >= 0 && l < COLS) {
                        if (_generation[k][l] && (k != i || l != j)) {
                            liveNeighbours++;
                        }
                    }
                }
            }
            
            // apply the rules
            if (_generation[i][j]) {
                if (liveNeighbours < 2 || liveNeighbours > 3) {
                    _next_generation[i][j] = false;
                } else {
                    _next_generation[i][j] = true;
                }
            } else {
                if (liveNeighbours == 3) {
                    _next_generation[i][j] = true;
                } else {
                    _next_generation[i][j] = false;
                }
            }
        }
    }
    
    // copy the next generation to the current generation
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            _generation[i][j] = _next_generation[i][j];
        }
    }
}


/**
 Draws the current generation
 */
void game_of_life::draw() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (_generation[i][j]) {
                cout << "X";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}


