#include "Database.h"
#include <iostream>
using namespace std;

Database::~Database() {
    for (auto item : items) {
        delete item;
    }
}

void Database::add(media::Media* item) {
    items.push_back(item);
}

void Database::remove(int id) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it;
            items.erase(it);
            cout << "Removed item with ID: " << id << endl;
            return;
        }
    }
    cout << "ID not found.\n";
}

void Database::list() const {
    for (const auto& item : items) {
        item->showInfo();
    }
}
