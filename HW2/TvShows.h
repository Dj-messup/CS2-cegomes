#pragma once
#include "Media.h"
using namespace std;

namespace tvshows {
    class TvShow : public media::Media {
    private:
        int numEpisodes;  // how many episodes in show

    public:
        // make new tv show
        TvShow(int id, string title, int year, string genre, float rating, int episodes);
        
        // get number of episodes
        int getEpisodes() { return numEpisodes; }
        
        // print tv show info
        string displayInfo();
    };
}