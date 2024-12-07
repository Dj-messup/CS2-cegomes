#pragma once
#include <string>
#include <vector>
#include "Enemy.h"

using namespace std;

class Room {
private:
    string description;
    vector<Enemy*> enemies;
    Room* nextRoom;

public:
    Room(string desc);
    void addEnemy(Enemy* enemy);
    void setNextRoom(Room* room);
    void displayRoom();
    Room* getNextRoom();
};




