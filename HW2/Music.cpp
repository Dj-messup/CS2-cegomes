#include "Music.h"
#include <iostream>
using namespace std;

namespace music {
    Music::Music(int id, const string& title, int year, const string& artist)
        : Media(id, title, year), artist(artist) {}

    string Music::getArtist() const { return artist; }

    void Music::showInfo() const {
        cout << "Music: " << title << " (" << year << "), Artist: " << artist << endl;
    }
}

