//
//  main.cpp
//  game_of_life
//
//  Created by Dario Caric on 14.04.2024..
//

#include <iostream>
#include "game_of_life.hpp"
#include <thread>
#include <stdlib.h>
#include <chrono>

using namespace std;
int main() {
    
    cout << "Welcome to the Game of Life!" << endl;
    cout << "Press Ctrl+C to stop the game." << endl;
    cout << "Enter percentage of live cells (0-100):";
    int percentage;
    cin >> percentage;
    if (percentage < 0 || percentage > 100) {
        cerr << "Percentage must be between 0 and 100." << endl;
        return 1;
    }
    
    // initializes the game
    game_of_life gameOfLife(percentage);
    
    int cycle = 0;
    //for (int i = 0; i < 500; i++) {
    while (true) {
        cycle++;
        // draws the game
        gameOfLife.draw(cycle);
        
        // runs next generation
        gameOfLife.next_generation();
        
        // waits for 2 second
        this_thread::sleep_for(std::chrono::milliseconds(100));
        
        // Clears the console for windos and macos/linux
        #ifdef _WIN32
            system("cls");
        #else
            // Set the TERM environment variable
            setenv("TERM", "xterm", 1);
            //system("clear");
            char* term_type = getenv("TERM");
            if (term_type == nullptr) {
                cerr << "Terminal type is not set. Some operations may not work." << endl;
                // Handle accordingly, perhaps by avoiding clear screen or other terminal-specific functions
            } else {
                system("clear");
            }
        #endif
    }
    
    return 0;
}
