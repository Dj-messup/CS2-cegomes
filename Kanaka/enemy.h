#pragma once
#include <string>

using namespace std;

class Enemy
{
private:
    string name;  // Enemy's name
    int health;        // Enemy's health
    int damage;        // Enemy's damage

public:
    // Constructor to initialize enemy with name, health, and damage
    Enemy(string enemyName, int enemyHealth, int enemyDamage)
        : name(enemyName), health(enemyHealth), damage(enemyDamage)
    {}

    // Getter for enemy name
    string getName() { return name; }

    // Getter for enemy health
    int getHealth() { return health; }

    // Getter for enemy damage
    int getDamage() { return damage; }

    // Take damage
    void takeDamage(int amount)
    {
        health -= amount;
        if (health <= 0)
        {
            cout << name << " has been defeated!" << endl;
        }
    }

    // Attack the player
    void attack()
    {
        cout << name << " attacks you for " << damage << " damage!" << endl;
    }
};

