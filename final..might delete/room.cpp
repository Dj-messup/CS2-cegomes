#include "Room.h"
#include <iostream>

using namespace std;

Room::Room(string desc) : description(desc), nextRoom(nullptr) {}

void Room::addEnemy(Enemy* enemy) {
    enemies.push_back(enemy);
}

void Room::setNextRoom(Room* room) {
    nextRoom = room;
}

void Room::displayRoom() {
    cout << description << endl;

    if (!enemies.empty()) {
        cout << "You encounter an enemy: " << enemies[0]->getName() << "!" << endl;
        cout << "Prepare to fight!" << endl;
    }

    cout << "Do you want to proceed to the next room? (yes/no): ";
}

Room* Room::getNextRoom() {
    return nextRoom;
}


