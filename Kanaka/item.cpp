#include "Item.h"
#include <iostream>

using namespace std;

Item::Item(string name, string effect) : name(name), effect(effect) {}

string Item::getName() const {
    return name;
}

void Item::use(Player& player) {
    cout << "Using " << name << ": " << effect << endl;
    if (effect == "heal") {
        player.takeDamage(-20); // Heal 20 health points
        cout << "You feel refreshed! Health restored." << endl;
    } else if (effect == "boost") {
        cout << "Your attacks feel stronger temporarily!" << endl;
    } else {
        cout << "The effect is unknown!" << endl;
    }
}

