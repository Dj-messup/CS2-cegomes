#pragma once
#include "Media.h"
using namespace std;

namespace movies {
    class Movie : public media::Media {
    private:
        string director;  // who directed the movie

    public:
        // constructor
        Movie(int id, string title, int year, string genre, float rating, string director);
        
        // get the director
        string getDirector() { return director; }
        
        // show movie info
        string displayInfo();
    };
}
