#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(string name, int health, int charisma, int strength)
    : name(name), health(health), charisma(charisma), strength(strength) {}

void Player::addItem(Item* item) {
    inventory.push_back(item);
}

void Player::takeDamage(int damage) {
    health -= damage;
}

int Player::getHealth() {
    return health;
}

void Player::displayInventory() {
    cout << "Inventory: " << endl;
    for (auto& item : inventory) {
        cout << item->getName() << endl;
    }
}

void Player::setHealth(int health) {
    this->health = health;
}
