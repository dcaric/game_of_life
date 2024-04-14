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
    
    // initializes the game
    game_of_life gameOfLife;
    
    for (int i = 0; i < 10; i++) {
        // runs next generation
        gameOfLife.next_generation();
        
        // draws the game
        gameOfLife.draw();
        
        // waits for 2 second
        this_thread::sleep_for(std::chrono::milliseconds(2000));
        
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
