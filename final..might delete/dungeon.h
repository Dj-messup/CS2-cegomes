#pragma once
#include "Room.h"

using namespace std;

class Dungeon {
private:
    Room* mainGate;

public:
    Dungeon();
    void start();
};


