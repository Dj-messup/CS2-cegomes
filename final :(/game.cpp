#include "game.h"
#include <iostream>
/*All game mechanics
Main game loop 
Contains all the actual game code until void Game:: run
Void Game:: run() deals with game loop combat movement and items*/

// Constructor - Initialize the game with player's flag choice
Game::Game(string flag) : playerHealth(100), flagChoice(flag) {
    createDungeon();
}

// Destructor - Clean up memory when game ends
Game::~Game() {
    // Delete linked of list in rooms
    Room* current = currentRoom;
    while (current != nullptr) {
        Room* next = current->getNextRoom();
        delete current;
        current = next;
    }
    
    // Delete inventory items
    for (Item* item : inventory) {
        delete item;
    }
}

// Create the dungeon layout
void Game::createDungeon() {
    // Create all rooms
    Room* entrance = new Room("'Iolani Palace Entrance\nThe grand entrance stands before you.");
    Room* guardRoom = new Room("Palace Guard Room\nTwo Committee guards stand together, blocking your path.");
    Room* throneRoom = new Room("Throne Room\nThe sacred seat of Hawaiian monarchy.");
    Room* dungeon = new Room("Palace Dungeon\nA mysterious chamber beneath the palace.");

    // Add enemies
    guardRoom->setEnemy(new Enemy("Committee Guards", 40, 15,
        "Two armed members of the Committee of Safety stand together."));
    
    throneRoom->setEnemy(new Enemy("Sanford B. Dole", 60, 15,
        "The leader of the Committee of Safety, orchestrating the overthrow."));
    
    dungeon->setEnemy(new Enemy("Captain Cook's Ghost", 100, 20,
        "The vengeful spirit of Captain James Cook."));

    // Add items
    guardRoom->setItem(new Item("Lā'au Lapa'au (Medicine)", 40, 
        "Traditional Hawaiian healing medicine."));
        
    throneRoom->setItem(new Item("Ka Na'i Aupuni Spear", 25, 
        "A spear engraved with 'Ka Na'i Aupuni'", true));
        
    dungeon->setItem(new Item("JY Rifle", 35, 
        "A rifle bearing the initials 'JY'", true));

    // Link rooms together
    entrance->setNextRoom(guardRoom);
    guardRoom->setNextRoom(throneRoom);
    throneRoom->setNextRoom(dungeon);

    // Set starting room
    currentRoom = entrance;
}

// Add item to player's inventory
void Game::addToInventory(Item* item) {
    inventory.push_back(item);
    cout << "Added " << item->getName() << " to inventory!" << endl;
}

// Show Queen's Prayer based on flag choice
void Game::displayQueensPrayer() {
    cout << "\n============================================================\n";
    if (flagChoice == "Kanaka Maoli") {
        cout << R"(
`O kou aloha nô
Aia i ka lani
A `o Kou `oia `i`o
He hemolelo ho`i

Ko`u noho mihi `ana
A pa`ahao `ia
`O `oe ku`u lama
Kou nani ko`u ko`o

Mai nânâ `ino`ino
Nâ hewa o kânaka
Akä e huikala
A ma`ema`e nô

No laila e ka Haku
Ma lalo o kou `êheu
Kô mâkou maluhia
A mau loa aku nô

`Âmene)" << endl;
    }
    else {
        cout << R"(
Your love is in heaven
And your truth so perfect

I live in sorrow
Imprisoned
You are my light
Your glory, my support

Behold not with malevolence
The sins of man
But forgive
And cleanse

And so, O Lord
Protect us beneath your wings
And let peace be our portion
Now and forever more

Amen)" << endl;
    }
}

// Main game loop
void Game::run() {
    while (playerHealth > 0 && currentRoom != nullptr) {
        // Show current room and status
        currentRoom->display();
        cout << "\nHealth: " << playerHealth << "/100" << endl;
        
        // Show available actions
        cout << "\nAvailable actions:" << endl;
        vector<string> options;

        // Add possible actions based on current situation
        if (currentRoom->hasEnemy()) {
            options.push_back("Fight enemy");
        } else {
            options.push_back("Move to next room");
        }
        options.push_back("Search room");
        if (!inventory.empty()) {
            options.push_back("Use item");
        }

        // Display numbered options
        for (size_t i = 0; i < options.size(); i++) {
            cout << i + 1 << ". " << options[i] << endl;
        }

        // Get player's choice
        cout << "Enter your choice (1-" << options.size() << "): ";
        string choice;
        getline(cin, choice);

        try {
            int choiceNum = stoi(choice);
            
            // Check if choice is valid
            if (choiceNum < 1 || choiceNum > options.size()) {
                cout << "Invalid choice!" << endl;
                continue;
            }

            string selectedOption = options[choiceNum - 1];

            // Handle player's choice
            if (selectedOption == "Fight enemy") {
                Enemy* enemy = currentRoom->getEnemy();
                
                // Calculate damage with weapons, 
                //sums damage from all weapons in the inventory during combat
                int damage = 20;  // Base damage
                for (Item* item : inventory) {
                    if (item->getIsWeapon()) {
                        damage += item->getDamageAmount();
                        cout << "Using " << item->getName() << 
                             " (+" << item->getDamageAmount() << " damage)" << endl;
                    }
                }
                
                // Combat
                enemy->takeDamage(damage);
                if (!enemy->isDefeated()) {
                    enemy->attack(playerHealth);
                } else {
                    cout << "\n" << enemy->getName() << " has been defeated!" << endl;
                }
            }
            else if (selectedOption == "Move to next room") {
                currentRoom = currentRoom->getNextRoom();
                if (!currentRoom) {
                    // Victory!
                    cout << R"(
============================================================
                        Victory!
============================================================

'Onipa'a! (Be Steadfast, Stand Firm!)

You've reached Queen Lili'uokalani and preserved the 
sovereignty of the Hawaiian Kingdom! 

E ola ka Mo'i wahine! (Long live the Queen!)

E Onipa'a Kākou! (Let us all be steadfast together!)
============================================================
)" << endl;
                    break;
                }
            }
            else if (selectedOption == "Search room") {
                cout << "\nSearching room..." << endl;
                Item* foundItem = currentRoom->searchRoom();
                
                if (foundItem) {
                    cout << "\nFound " << foundItem->getName() << "!" << endl;
                    cout << foundItem->getDescription() << endl;
                    
                    if (foundItem->getIsWeapon()) {
                        cout << "Damage: " << foundItem->getDamageAmount() << endl;
                    } else {
                        cout << "Healing: " << foundItem->getHealAmount() << endl;
                    }
                    
                    cout << "Take item? (y/n): ";
                    string answer;
                    getline(cin, answer);
                    
                    if (answer == "y" || answer == "Y") {
                        addToInventory(foundItem);
                    } else {
                        delete foundItem;
                    }
                } else {
                    cout << "Found nothing." << endl;
                }
            }
            else if (selectedOption == "Use item") {
                // Show inventory
                cout << "\nInventory:" << endl;
                for (size_t i = 0; i < inventory.size(); i++) {
                    cout << i + 1 << ". " << inventory[i]->getName();
                    if (inventory[i]->getIsWeapon()) {
                        cout << " (Damage: " << inventory[i]->getDamageAmount() << ")";
                    } else {
                        cout << " (Healing: " << inventory[i]->getHealAmount() << ")";
                    }
                    cout << endl;
                }
                
                cout << "Choose item (1-" << inventory.size() << "): ";
                string itemChoice;
                getline(cin, itemChoice);
                
                try {
                    int index = stoi(itemChoice) - 1;
                    if (index >= 0 && index < inventory.size()) {
                        Item* selectedItem = inventory[index];
                        
                        if (!selectedItem->getIsWeapon()) {
                            playerHealth += selectedItem->getHealAmount();
                            if (playerHealth > 100) playerHealth = 100;
                            cout << "Used " << selectedItem->getName() << endl;
                            cout << "Health restored to " << playerHealth << endl;
                            delete inventory[index];
                            inventory.erase(inventory.begin() + index);
                        } else {
                            cout << "Weapons are used automatically in combat!" << endl;
                        }
                    }
                } catch (...) {
                    cout << "Invalid choice!" << endl;
                }
            }
        } catch (...) {
            cout << "Invalid input!" << endl;
        }

        // Check if player died
        if (playerHealth <= 0) {
            cout << "\nYou have fallen..." << endl;
            displayQueensPrayer();
            break;
        }
    }
}