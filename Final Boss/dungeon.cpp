#include "Dungeon.h"
#include "Room.h"
#include "Item.h"
#include "Enemy.h"
#include <iostream>

using namespace std;

Dungeon::Dungeon() {
    entrance = new Room("You are at the entrance of Iolani Palace. Two guards block your way.");
    hallway = new Room("You walk into a hallway filled with rats. Strange noises echo.");
    queenRoom = new Room("You've reached the Queen's Dungeon Room. She is trapped inside.");
    
    entrance->addItem(new Item("Spear", "boost"));
    entrance->addItem(new Item("Pistols", "boost"));
    entrance->addItem(new Item("Cheese and Wine", "heal"));
    
    hallway->addEnemy(new Enemy("Sanford B. Dole", 100, 10));  // Left room enemy
    queenRoom->addEnemy(new Enemy("John L. Stevens", 120, 15));  // Right room enemy

    entrance->setLeftRoom(hallway);
    hallway->setRightRoom(queenRoom);
}

void Dungeon::start() {
    entrance->displayRoom(player);
    queenRoom->finalBossFight(player);
}
