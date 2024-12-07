#include "Dungeon.h"
#include <iostream>

using namespace std;

Dungeon::Dungeon() {
    // Create rooms
    mainGate = new Room("You are at the Main Gate of 'Iolani Palace.");
    Room* guardRoom = new Room("You enter the Guard Room. A formidable enemy blocks your way.");
    Room* treasureRoom = new Room("You step into the Treasure Room. You've found the Queen's treasure!");

    // Add enemy to Guard Room
    guardRoom->addEnemy(new Enemy("Sanford B. Dole", 100));

    // Link rooms
    mainGate->setNextRoom(guardRoom);
    guardRoom->setNextRoom(treasureRoom);
}

void Dungeon::start() {
    Room* currentRoom = mainGate;

    while (currentRoom != nullptr) {
        currentRoom->displayRoom();

        string choice;
        cin >> choice;
        if (choice == "yes") {
            currentRoom = currentRoom->getNextRoom();
        } else {
            cout << "You decide to retreat. Game over." << endl;
            break;
        }
    }

    if (currentRoom == nullptr) {
        cout << "Congratulations! You've completed the dungeon!" << endl;
    }
}
