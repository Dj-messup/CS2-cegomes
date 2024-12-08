#include "Music.h"
#include <iostream>
using namespace std;

namespace music {
    Music::Music(int id, string title, int year, string genre, 
                 string composer, int tracks, int playtime)
        : Media(id, title, year, genre, 0) {  // Rating not used for music
        this->composer = composer;
        this->numTracks = tracks;
        this->totalPlaytime = playtime;
    }

    string Music::displayInfo() {
        string info = "Music: ";
        info += title;
        info += " (" + to_string(year) + ")";
        info += "\n  Genre: " + genre;
        info += "\n  Composer: " + composer;
        info += "\n  Tracks: " + to_string(numTracks);
        info += "\n  Playtime: " + to_string(totalPlaytime) + " minutes";
        return info;
    }
}
