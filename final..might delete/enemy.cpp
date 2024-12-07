#include "Enemy.h"

using namespace std;

Enemy::Enemy(string name, int health) : name(name), health(health) {}

string Enemy::getName() {
    return name;
}

