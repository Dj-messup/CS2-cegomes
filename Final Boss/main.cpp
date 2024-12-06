#include <iostream>
#include "Dungeon.h"
#include "Player.h"
#include "Room.h"
#include "Item.h"
#include "Enemy.h"

using namespace std;

void displayIntroduction(Player& player)
{
    cout << R"(
============================================================
             Welcome to the Kingdom of Hawai'i - 1893
============================================================

It's January 17, 1893. You stand at the gates of 'Iolani Palace, 
leading a protest against the overthrow of Queen Lili'uokalani. 
The Committee of Safety is trying to seize power, and you're 
fighting to protect your queen and your land.

For history's sake, she is in the second-floor bedroom, but 
for the game, the Queen is in a dungeon beneath the palace. 
Your mission: navigate the dungeon, face enemies, and save her!
============================================================
)";

    string name, flagChoice;
    cout << "Enter your name: ";
    getline(cin, name);

    player = Player(name, "");  // Initialize player with no flag yet

    // Flag choice selection
    while (true)
    {
        cout << "Choose your flag: \n";
        cout << "1. Ka Hae Hawai'i (Hawaiian Kingdom Flag) \n";
        cout << "2. Kanaka Maoli Flag \n";
        cout << "Enter your choice (1 or 2): ";
        getline(cin, flagChoice);

        if (flagChoice == "1")
        {
            cout << "You earn the title Robert Wilcox. The guards will let you pass!" << endl;
            player = Player(name, "Ka Hae Hawai'i");  // Charisma-based power
            break;
        }
        else if (flagChoice == "2")
        {
            cout << "You are proud of the Kanaka Maoli Flag!" << endl;
            player = Player(name, "Kanaka Maoli Flag");
            break;
        }
        else
        {
            cout << "Invalid choice. Please choose 1 or 2." << endl;
        }
    }
}

int main()
{
    Player player("", "");
    displayIntroduction(player);

    Dungeon dungeon(player);
    dungeon.start();

    return 0;
}



