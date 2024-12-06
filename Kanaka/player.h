#pragma once
#include <string>
#include <iostream>

using namespace std;

class Player
{
private:
    string name;   // Player's name
    string flagChoice;  // Flag choice (determines attributes)

public:
    // Constructor to initialize player with name and flag choice
    Player(string playerName, string playerFlagChoice)
        : name(playerName), flagChoice(playerFlagChoice)
    {}

    // Getter methods
    string getName() { return name; }
    string getFlagChoice() { return flagChoice; }

    // Function to display player's status based on flag choice
    void displayPlayerInfo()
    {
        cout << "Player: " << name << endl;
        cout << "Flag Choice: " << flagChoice << endl;
    }
};




