#pragma once
#include "Media.h"
using namespace std;

namespace tvshows 
{
    class TvShow : public media::Media 
    {
    private:
        int numEpisodes;

    public:
        TvShow(int id, string title, int year, string genre, 
               float rating, int episodes);
        
        int getEpisodes() { return numEpisodes; }
        string displayInfo();
    };
}
