#include "Room.h"
#include <iostream>

using namespace std;

Room::Room(string desc) : description(desc), leftRoom(nullptr), rightRoom(nullptr) {}

void Room::addItem(Item* item) {
    items.push_back(item);
}

void Room::addEnemy(Enemy* enemy) {
    enemies.push_back(enemy);
}

void Room::setLeftRoom(Room* room) {
    leftRoom = room;
}

void Room::setRightRoom(Room* room) {
    rightRoom = room;
}

void Room::displayRoom(Player& player) {
    cout << description << endl;
    cout << "Choose your next action:" << endl;
    cout << "1. Go left" << endl;
    cout << "2. Go right" << endl;
    
    int choice;
    cin >> choice;
    
    if (choice == 1 && leftRoom) {
        leftRoom->mongooseEncounter(player);
    } else if (choice == 2 && rightRoom) {
        rightRoom->herbalMedicineEncounter(player);
    }
}

void Room::chooseItem(Player& player) {
    cout << "Do you want to take any items?" << endl;
    for (int i = 0; i < items.size(); i++) {
        cout << i + 1 << ". " << items[i]->getName() << endl;
    }
    int choice;
    cin >> choice;
    if (choice > 0 && choice <= items.size()) {
        items[choice - 1]->use(player);
    }
}

void Room::mongooseEncounter(Player& player) {
    cout << "You encounter a mongoose (Hawaiian rat)!" << endl;
    if (find_if(items.begin(), items.end(), [](Item* item) { return item->getName() == "Cheese and Wine"; }) != items.end()) {
        cout << "You feed the mongoose some cheese, and it scurries away!" << endl;
    } else {
        cout << "The mongoose attacks you! You take 5 damage!" << endl;
        player.takeDamage(5);
    }
}

void Room::herbalMedicineEncounter(Player& player) {
    cout << "You find a pot of Lāʻau lapaʻau (Herbal Medicine)!" << endl;
    cout << "You gain 10 health!" << endl;
    player.setHealth(player.getHealth() + 10);
}

void Room::finalBossFight(Player& player) {
    cout << "You've reached the final room! Captain Cooke's ghost appears!" << endl;
    Enemy captainCooke("Captain Cooke's Ghost", 20, 10);
    while (captainCooke.getHealth() > 0) {
        cout << "You have to fight the ghost! It has " << captainCooke.getHealth() << " health." << endl;
        cout << "Press 1 to attack!" << endl;
        
        int attackChoice;
        cin >> attackChoice;
        
        if (attackChoice == 1) {
            captainCooke.takeDamage(10);
            cout << "You hit Captain Cooke's ghost! It's now at " << captainCooke.getHealth() << " health." << endl;
            
            if (captainCooke.getHealth() > 0) {
                cout << "Captain Cooke's ghost attacks you for 10 damage!" << endl;
                player.takeDamage(10);
                if (player.getHealth() <= 0) {
                    cout << "You have died!" << endl;
                    return;
                }
            }
        }
    }
    cout << "You defeated Captain Cooke's ghost! You have saved Queen Lili'uokalani!" << endl;
}

