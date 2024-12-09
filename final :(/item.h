// item.h
#pragma once
#include <string>
using namespace std;

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