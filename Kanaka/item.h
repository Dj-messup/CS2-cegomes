#pragma once
#include <string>

using namespace std;

class Item
{
private:
    string name;  // Item's name
    string effect; // Item's effect (e.g., healing, boosting)

public:
    // Constructor to initialize item with name and effect
    Item(string itemName, string itemEffect)
        : name(itemName), effect(itemEffect)
    {}

    // Getter for item name
    string getName() { return name; }

    // Getter for item effect
    string getEffect() { return effect; }

    // Use the item
    void use()
    {
        cout << "You use " << name << ". Effect: " << effect << endl;
    }
};

