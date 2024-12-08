#include "Database.h"
#include <iostream>
#include <fstream>
using namespace std;


Database::Database() {
    movieCount = 0;
    tvCount = 0;
    musicCount = 0;
}

// add movie from CSV line
void Database::addMovie(string line) {
    if(movieCount >= 100) {
        cout << "Too many movies!" << endl;
        return;
    }

    // split the line by commas
    int pos = line.find(',');
    string id = line.substr(0, pos);
    line = line.substr(pos + 1);

    pos = line.find(',');
    string title = line.substr(0, pos);
    line = line.substr(pos + 1);

    pos = line.find(',');
    string yearStr = line.substr(0, pos);
    line = line.substr(pos + 1);

    pos = line.find(',');
    string genre = line.substr(0, pos);
    line = line.substr(pos + 1);

    pos = line.find(',');
    string ratingStr = line.substr(0, pos);
    string director = line.substr(pos + 1);

    // convert strings to numbers
    int movieId = atoi(id.substr(2).c_str());
    int year = atoi(yearStr.c_str());
    float rating = atof(ratingStr.c_str());

    // make new movie and add to list
    movieList[movieCount] = new movies::Movie(movieId, title, year, genre, rating, director);
    movieCount++;
}

// add tv show from CSV line
void Database::addTvShow(string line) {
    if(tvCount >= 100) {
        cout << "Too many shows!" << endl;
        return;
    }

    // split the line by commas (same as movies)
    int pos = line.find(',');
    string id = line.substr(0, pos);
    line = line.substr(pos + 1);

    pos = line.find(',');
    string title = line.substr(0, pos);
    line = line.substr(pos + 1);

    pos = line.find(',');
    string yearStr = line.substr(0, pos);
    line = line.substr(pos + 1);

    pos = line.find(',');
    string genre = line.substr(0, pos);
    line = line.substr(pos + 1);

    pos = line.find(',');
    string ratingStr = line.substr(0, pos);
    string episodesStr = line.substr(pos + 1);

    // convert strings to numbers
    int showId = atoi(id.substr(4).c_str());
    int year = atoi(yearStr.c_str());
    float rating = atof(ratingStr.c_str());
    int episodes = atoi(episodesStr.c_str());

    tvList[tvCount] = new tvshows::TvShow(showId, title, year, genre, rating, episodes);
    tvCount++;
}

// add music from CSV line
void Database::addMusic(string line) {
    if(musicCount >= 100) {
        cout << "Too many music!" << endl;
        return;
    }

    // split line by commas again
    int pos = line.find(',');
    string id = line.substr(0, pos);
    line = line.substr(pos + 1);

    pos = line.find(',');
    string title = line.substr(0, pos);
    line = line.substr(pos + 1);

    pos = line.find(',');
    string yearStr = line.substr(0, pos);
    line = line.substr(pos + 1);

    pos = line.find(',');
    string composer = line.substr(0, pos);
    line = line.substr(pos + 1);

    pos = line.find(',');
    string genre = line.substr(0, pos);
    line = line.substr(pos + 1);

    pos = line.find(',');
    string tracksStr = line.substr(0, pos);
    string playtimeStr = line.substr(pos + 1);

    // convert strings to numbers
    int musicId = atoi(id.substr(2).c_str());
    int year = atoi(yearStr.c_str());
    int tracks = atoi(tracksStr.c_str());
    int playtime = atoi(playtimeStr.c_str());

    musicList[musicCount] = new music::Music(musicId, title, year, genre, composer, tracks, playtime);
    musicCount++;
}

// show everything in database
void Database::displayAll() {
    cout << "\nMOVIES:\n";
    for(int i = 0; i < movieCount; i++) {
        cout << movieList[i]->displayInfo() << endl;
    }

    cout << "\nTV SHOWS:\n";
    for(int i = 0; i < tvCount; i++) {
        cout << tvList[i]->displayInfo() << endl;
    }

    cout << "\nMUSIC:\n";
    for(int i = 0; i < musicCount; i++) {
        cout << musicList[i]->displayInfo() << endl;
    }
}

// find media by title
void Database::searchByTitle(string searchTitle) {
    cout << "Searching for: " << searchTitle << endl;
    bool found = false;

    // check movies
    for(int i = 0; i < movieCount; i++) {
        if(movieList[i]->getTitle() == searchTitle) {
            cout << "Found Movie: " << movieList[i]->displayInfo() << endl;
            found = true;
        }
    }

    // check tv shows
    for(int i = 0; i < tvCount; i++) {
        if(tvList[i]->getTitle() == searchTitle) {
            cout << "Found TV Show: " << tvList[i]->displayInfo() << endl;
            found = true;
        }
    }

    // check music
    for(int i = 0; i < musicCount; i++) {
        if(musicList[i]->getTitle() == searchTitle) {
            cout << "Found Music: " << musicList[i]->displayInfo() << endl;
            found = true;
        }
    }

    if(!found) {
        cout << "Nothing found with that title" << endl;
    }
}

// remove media with given id
void Database::removeMedia(int id) {
    // check movies
    for(int i = 0; i < movieCount; i++) {
        if(movieList[i]->getId() == id) {
            delete movieList[i];
            // move everything down one spot
            for(int j = i; j < movieCount - 1; j++) {
                movieList[j] = movieList[j + 1];
            }
            movieCount--;
            cout << "Removed movie with ID: " << id << endl;
            return;
        }
    }

    // check tv shows 
    for(int i = 0; i < tvCount; i++) {
        if(tvList[i]->getId() == id) {
            delete tvList[i];
            for(int j = i; j < tvCount - 1; j++) {
                tvList[j] = tvList[j + 1];
            }
            tvCount--;
            cout << "Removed TV show with ID: " << id << endl;
            return;
        }
    }

    // check music
    for(int i = 0; i < musicCount; i++) {
        if(musicList[i]->getId() == id) {
            delete musicList[i];
            for(int j = i; j < musicCount - 1; j++) {
                musicList[j] = musicList[j + 1];
            }
            musicCount--;
            cout << "Removed music with ID: " << id << endl;
            return;
        }
    }

    cout << "Couldn't find anything with ID: " << id << endl;
}