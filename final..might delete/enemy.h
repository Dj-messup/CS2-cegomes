#pragma once
#include <string>

using namespace std;

class Enemy {
private:
    string name;
    int health;

public:
    Enemy(string name, int health);
    string getName();
};

