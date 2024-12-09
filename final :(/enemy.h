#pragma once
#include <string>
using namespace std;
/* fills out an enemy card, says what enemies should have
and what they can do*/

class Enemy {
private:
    string name;
    int health;
    int damage;
    string description;

public:
    Enemy(string n, int h, int d, string desc);
    void attack(int& playerHealth);
    void takeDamage(int amount);
    string getName();
    string getDescription();
    bool isDefeated();
};