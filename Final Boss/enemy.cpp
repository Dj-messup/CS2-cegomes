#include "Enemy.h"
#include <iostream>

using namespace std;

Enemy::Enemy(string name, int health, int attack)
    : name(name), health(health), attack(attack) {}

void Enemy::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0; // Ensure health doesn't go negative
}

int Enemy::getHealth() {
    return health;
}

int Enemy::getAttack() {
    return attack;
}

string Enemy::getName() {
    return name;
}
