#pragma once
#include "Movie.h"
#include "TvShows.h"
#include "Music.h"
using namespace std;

class Database {
private:
    // arrays to hold our stuff
    movies::Movie* movieList[100];
    tvshows::TvShow* tvList[100];
    music::Music* musicList[100];
    
    // keep track of counts
    int movieCount;
    int tvCount;
    int musicCount;

public:
    // constructor
    Database();

    // functions to add stuff
    void addMovie(string line);
    void addTvShow(string line);
    void addMusic(string line);

    // functions to work with files
    bool loadFile(string filename);
    void saveToFiles();

    // other functions
    void removeMedia(int id);
    void displayAll();
    void searchByTitle(string title);
};