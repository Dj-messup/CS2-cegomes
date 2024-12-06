#pragma once
#include "Room.h"
#include "Player.h"

using namespace std;

class Dungeon
{
private:
    Room* startRoom;  // Starting room
    Player& player;   // Reference to the player

public:
    Dungeon(Player& p) : player(p)
    {
        // Set up the dungeon layout and rooms
        startRoom = new Room("You are at the entrance of the dungeon. There's a hallway ahead.");
        Room* secondRoom = new Room("You enter a dark room with a mysterious presence.");
        Room* thirdRoom = new Room("You find a treasure chest, but it's guarded by an enemy!");

        startRoom->setNextRoom(secondRoom);
        secondRoom->setNextRoom(thirdRoom);

        // Populate rooms with items and enemies
        Item* cheese = new Item("Cheese", "Feed it to a mongoose to avoid damage.");
        Item* herbalMedicine = new Item("Herbal Medicine", "Restores 10 health.");
        Enemy* mongoose = new Enemy("Mongoose", 20, 5);
        Enemy* captainCook = new Enemy("Captain Cook's Ghost", 20, 10);

        secondRoom->addItem(cheese);
        secondRoom->addEnemy(mongoose);
        thirdRoom->addItem(herbalMedicine);
        thirdRoom->addEnemy(captainCook);
    }

    // Start the game
    void start()
    {
        Room* currentRoom = startRoom;
        bool gameOver = false;

        while (!gameOver)
        {
            currentRoom->displayRoom();

            // Player chooses to either move to the next room, fight, or use item
            string action;
            cout << "What do you want to do? (move/fight/use item): ";
            getline(cin, action);

            if (action == "move")
            {
                if (currentRoom->nextRoom != nullptr)
                {
                    currentRoom = currentRoom->nextRoom;
                }
                else
                {
                    cout << "You have reached the end of the dungeon!" << endl;
                    gameOver = true;
                }
            }
            else if (action == "fight")
            {
                if (currentRoom->enemy != nullptr)
                {
                    cout << "You are fighting " << currentRoom->enemy->getName() << "!" << endl;
                    currentRoom->enemy->attack();
                    // Combat logic here...
                }
            }
            else if (action == "use item")
            {
                if (currentRoom->item != nullptr)
                {
                    currentRoom->item->use();
                    // Healing or other effects based on item...
                }
            }
        }
    }
};


