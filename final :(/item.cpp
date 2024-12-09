// item.cpp
#include "item.h"

// Constructor: set up a new item
Item::Item(string n, int amount, string desc, bool weapon) 
    : name(n), healAmount(weapon ? 0 : amount), 
      damageAmount(weapon ? amount : 0), 
      description(desc), isWeapon(weapon) {}

// Getter functions - return private data
string Item::getName() { return name; }
int Item::getHealAmount() { return healAmount; }
int Item::getDamageAmount() { return damageAmount; }
string Item::getDescription() { return description; }
bool Item::getIsWeapon() { return isWeapon; }

