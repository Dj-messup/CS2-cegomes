#pragma once
#include <string>
using namespace std;
/*handles an item tag, shows what an item needs to have
how much it heals, how much damage it adds
shows the item description.. says what an item can do*/

class Item {
private:
    string name;
    int healAmount;
    int damageAmount;
    string description;
    bool isWeapon;

public:
    Item(string n, int amount, string desc, bool weapon = false);
    string getName();
    int getHealAmount();
    int getDamageAmount();
    string getDescription();
    bool getIsWeapon();
};