#pragma once
#include "Movie.h"
#include "TvShows.h"
#include "Music.h"
using namespace std;

class Database {
private:
    string name;
    movies::Movie* movieList[100];
    tvshows::TvShow* tvList[100];
    music::Music* musicList[100];
    int movieCount;
    int tvCount;
    int musicCount;

public:
    Database();
    void addMovie(string line);
    void addTvShow(string line);
    void addMusic(string line);
    void removeMedia(int id);
    void displayAll();
    void searchByTitle(string title);
    void loadFile(string filename);
};
