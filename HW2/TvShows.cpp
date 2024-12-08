#include "TvShows.h"
#include <iostream>
using namespace std;

namespace tvshows {
    TvShow::TvShow(int id, const string& title, int year, int seasons)
        : Media(id, title, year), seasons(seasons) {}

    int TvShow::getSeasons() const { return seasons; }

    void TvShow::showInfo() const {
        cout << "TV Show: " << title << " (" << year << "), Seasons: " << seasons << endl;
    }
}

