#pragma once
#include <string>
#include "Item.h"
#include "Enemy.h"

using namespace std;

class Room
{
public:
    string description;  // Room description
    Item* item;               // Item in the room (if any)
    Enemy* enemy;             // Enemy in the room (if any)
    Room* nextRoom;           // Pointer to next room

    // Constructor to initialize room with a description
    Room(string roomDescription)
        : description(roomDescription), item(nullptr), enemy(nullptr), nextRoom(nullptr)
    {}

    // Destructor to clean up dynamically allocated objects
    ~Room()
    {
        delete item;
        delete enemy;
    }

    // Add item to the room
    void addItem(Item* newItem)
    {
        item = newItem;
    }

    // Add enemy to the room
    void addEnemy(Enemy* newEnemy)
    {
        enemy = newEnemy;
    }

    // Set the next room in the dungeon
    void setNextRoom(Room* next)
    {
        nextRoom = next;
    }

    // Display room description
    void displayRoom()
    {
        cout << description << endl;
        if (item != nullptr)
        {
            cout << "You see an item: " << item->getName() << endl;
        }
        if (enemy != nullptr)
        {
            cout << "An enemy appears: " << enemy->getName() << endl;
        }
    }
};




