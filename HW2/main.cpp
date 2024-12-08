#include <iostream>
#include "Movies.h"
#include "TvShows.h"
#include "Music.h"
#include "Database.h"
using namespace std;

int main() {
    Database db;

    db.add(new movies::Movie(1, "Inception", 2010, "Christopher Nolan"));
    db.add(new tvshows::TvShow(2, "Breaking Bad", 2008, 5));
    db.add(new music::Music(3, "Bohemian Rhapsody", 1975, "Queen"));

    cout << "Media List:\n";
    db.list();

    db.remove(2);
    cout << "After Removal:\n";
    db.list();

    return 0;
}

