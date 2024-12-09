#pragma once
#include "enemy.h"
#include "item.h"
#include <string>
using namespace std;
/*says what a room needs and what CAN do as a blueprint*/

class Room {
private:
    string description;  // Room description
    Enemy* enemy;       // Enemy in room
    Item* item;         // Item in room
    Room* nextRoom;     // Next room (linked list)

public:
    Room(string desc);
    void setEnemy(Enemy* e);
    void setItem(Item* i);
    void setNextRoom(Room* next);
    Room* getNextRoom();
    Enemy* getEnemy();
    bool hasEnemy();
    Item* searchRoom();
    void display();
};

