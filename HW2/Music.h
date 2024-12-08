#pragma once
#include "Media.h"
using namespace std;

namespace music {
    class Music : public media::Media {
    private:
        string composer;
        int numTracks;
        int totalPlaytime;

    public:
        Music(int id, string title, int year, string genre, 
              string composer, int tracks, int playtime);
        
        string getComposer() { return composer; }
        int getTracks() { return numTracks; }
        int getPlaytime() { return totalPlaytime; }
        
        string displayInfo();
    };
}
