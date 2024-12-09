#pragma once
#include "room.h"
#include <vector>
using namespace std;
/*Blueprint for the game class
Tells other files what game can do
Defines the structure what things the game 
class will have and what it can do*/

class Game {
private:
    Room* currentRoom;         // Current room player is in
    int playerHealth;          // Player's health (max 100)
    vector<Item*> inventory;   // Player's inventory
    string flagChoice;         // Player's chosen flag

    void createDungeon();      // Set up the rooms
    void displayQueensPrayer();
    void addToInventory(Item* item);

public:
    Game(string flag);
    ~Game();                   // Cleanup memory
    void run();                // Main game loop
};