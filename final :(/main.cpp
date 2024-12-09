#include "game.h"
#include <iostream>
using namespace std;
/*greets player, gets initial choices
Creates the Game object
Very simple, just starts everything */

// Get player's flag choice
string getFlagChoice() {
    string choice;
    
    while (true) {
        cout << R"(
============================================================
             Welcome to the Kingdom of Hawai'i - 1893
============================================================

Choose your flag:
1. Ka Hae Hawai'i (Hawaiian Kingdom Flag)
2. Kanaka Maoli Flag

Enter your choice (1 or 2): )";

        getline(cin, choice);

        if (choice == "1") {
            cout << "\nYou carry the Ka Hae Hawai'i!" << endl;
            return "Ka Hae Hawaii";
        }
        else if (choice == "2") {
            cout << "\nYou proudly bear the Kanaka Maoli flag!" << endl;
            return "Kanaka Maoli";
        }
        else {
            cout << "\nInvalid choice. Please enter 1 or 2." << endl;
            cout << "Press Enter to try again...";
            cin.get();
            for(int i = 0; i < 50; i++) cout << endl;  // Clear screen
        }
    }
}

int main() {
    // Get player's flag choice
    string flagChoice = getFlagChoice();
    
    // Show mission briefing
    cout << R"(
============================================================
                    Mission Briefing
============================================================
The Committee of Safety has launched their coup against 
Queen Lili'uokalani. You must:
- Fight through the palace
- Face the Committee Guards
- Defeat Sanford B. Dole
- Overcome Captain Cook's Ghost

Your mission: Save the Queen!
============================================================
)" << endl;

    cout << "Press Enter to begin...";
    cin.get();

    // Start the game
    Game game(flagChoice);
    game.run();

    return 0;
}