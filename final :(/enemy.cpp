#include "enemy.h"
#include <iostream>

// Constructor: set up a new enemy
Enemy::Enemy(string n, int h, int d, string desc) 
    : name(n), health(h), damage(d), description(desc) {}

// Attack the player
void Enemy::attack(int& playerHealth) {
    cout << name << " attacks!" << endl;
    playerHealth -= damage;
    cout << "The attack deals " << damage << " damage!" << endl;
}

// Take damage from player
void Enemy::takeDamage(int amount) {
    health -= amount;
    cout << name << " takes " << amount << " damage!" << endl;
    if (health > 0) {
        cout << name << "'s health: " << health << endl;
    }
}

// Getter functions
string Enemy::getName() { return name; }
string Enemy::getDescription() { return description; }
bool Enemy::isDefeated() { return health <= 0; }