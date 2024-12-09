#include "room.h"
#include <iostream>
/*says what a room needs and what 
CAN do and does those things, is the constructor */

//create a new room
Room::Room(string desc) 
    : description(desc), enemy(nullptr), item(nullptr), nextRoom(nullptr) {}

// Set up room contents
void Room::setEnemy(Enemy* e) { enemy = e; }
void Room::setItem(Item* i) { item = i; }
void Room::setNextRoom(Room* next) { nextRoom = next; }

// Get room contents
Room* Room::getNextRoom() { return nextRoom; }
Enemy* Room::getEnemy() { return enemy; }
bool Room::hasEnemy() { return enemy != nullptr && !enemy->isDefeated(); }

// Search room for items
Item* Room::searchRoom() {
    if (item != nullptr) {
        Item* foundItem = item;
        item = nullptr;  // Remove item from room
        return foundItem;
    }
    return nullptr;  // Nothing found
}

// Show room description
void Room::display() {
    cout << "\n=== " << description << " ===" << endl;
    
    // Only show enemy if not defeated
    if (hasEnemy()) {
        cout << enemy->getName() << " is here!" << endl;
        cout << enemy->getDescription() << endl;
    }
}