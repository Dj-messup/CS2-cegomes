#pragma once
#include "Media.h"
using namespace std;

namespace music {
    class Music : public media::Media {
    private:
        string composer;     // who made the music
        int numTracks;       // number of songs
        int totalPlaytime;   // how long album is

    public:
        // constructor for music
        Music(int id, string title, int year, string genre, string composer, 
              int tracks, int playtime);
        
        // get functions
        string getComposer() { return composer; }
        int getTracks() { return numTracks; }
        int getPlaytime() { return totalPlaytime; }
        
        // display music info
        string displayInfo();
    };
}
