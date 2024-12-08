#include "Database.h"
#include <iostream>
#include <fstream>
using namespace std;

// start with empty database
Database::Database() {
    movieCount = 0;
    tvCount = 0;
    musicCount = 0;
}

// add a movie from the csv line
void Database::addMovie(string line) {
    // make sure we have room
    if(movieCount >= 100) {
        cout << "Sorry, too many movies!\n";
        return;
    }

    // get each piece of info from the line
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

    // convert strings to numbers (skipping "tt" in id)
    int movieId = atoi(id.substr(2).c_str());
    int year = atoi(yearStr.c_str());
    float rating = atof(ratingStr.c_str());

    // make new movie and add it
    movieList[movieCount] = new movies::Movie(movieId, title, year, genre, rating, director);
    movieCount++;
}

// add a tv show from the csv line
void Database::addTvShow(string line) {
    // check if we have room
    if(tvCount >= 100) {
        cout << "Sorry, too many TV shows!\n";
        return;
    }

    // get info from line
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

    // convert to numbers (skip "tmdb")
    int showId = atoi(id.substr(4).c_str());
    int year = atoi(yearStr.c_str());
    float rating = atof(ratingStr.c_str());
    int episodes = atoi(episodesStr.c_str());

    // add new show
    tvList[tvCount] = new tvshows::TvShow(showId, title, year, genre, rating, episodes);
    tvCount++;
}

// add music from csv line
void Database::addMusic(string line) {
    if(musicCount >= 100) {
        cout << "Sorry, too many music albums!\n";
        return;
    }

    // get the info
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

    // convert numbers (skip "mw")
    int musicId = atoi(id.substr(2).c_str());
    int year = atoi(yearStr.c_str());
    int tracks = atoi(tracksStr.c_str());
    int playtime = atoi(playtimeStr.c_str());

    // add new music
    musicList[musicCount] = new music::Music(musicId, title, year, genre, composer, tracks, playtime);
    musicCount++;
}

// load stuff from file
bool Database::loadFile(string filename) {
    // try to open file
    ifstream file;
    file.open(filename);
    
    if(!file.is_open()) {
        cout << "Can't open " << filename << endl;
        return false;
    }

    string line;
    getline(file, line);  // skip header
    
    // read each line and add it
    while(getline(file, line)) {
        if(filename == "movies.csv") {
            addMovie(line);
        }
        else if(filename == "tvshows.csv") {
            addTvShow(line);
        }
        else if(filename == "music.csv") {
            addMusic(line);
        }
    }
    file.close();
    return true;
}

// display everything in database
void Database::displayAll() {
    cout << "\nAll Movies:\n";
    for(int i = 0; i < movieCount; i++) {
        cout << movieList[i]->displayInfo() << endl;
    }

    cout << "\nAll TV Shows:\n";
    for(int i = 0; i < tvCount; i++) {
        cout << tvList[i]->displayInfo() << endl;
    }

    cout << "\nAll Music:\n";
    for(int i = 0; i < musicCount; i++) {
        cout << musicList[i]->displayInfo() << endl;
    }
}

// remove something using its ID
void Database::removeMedia(int id) {
    // check movies first
    for(int i = 0; i < movieCount; i++) {
        if(movieList[i]->getId() == id) {
            delete movieList[i];
            // move everything down one spot
            for(int j = i; j < movieCount - 1; j++) {
                movieList[j] = movieList[j + 1];
            }
            movieCount--;
            cout << "Removed movie " << id << endl;
            return;
        }
    }

    // then check tv shows
    for(int i = 0; i < tvCount; i++) {
        if(tvList[i]->getId() == id) {
            delete tvList[i];
            for(int j = i; j < tvCount - 1; j++) {
                tvList[j] = tvList[j + 1];
            }
            tvCount--;
            cout << "Removed TV show " << id << endl;
            return;
        }
    }

    // finally check music
    for(int i = 0; i < musicCount; i++) {
        if(musicList[i]->getId() == id) {
            delete musicList[i];
            for(int j = i; j < musicCount - 1; j++) {
                musicList[j] = musicList[j + 1];
            }
            musicCount--;
            cout << "Removed music " << id << endl;
            return;
        }
    }

    cout << "Couldn't find anything with ID " << id << endl;
}

// search for something by title
void Database::searchByTitle(string title) {
    bool found = false;

    // check movies
    for(int i = 0; i < movieCount; i++) {
        if(movieList[i]->getTitle() == title) {
            cout << "Found movie: " << movieList[i]->displayInfo() << endl;
            found = true;
        }
    }

    // check tv shows
    for(int i = 0; i < tvCount; i++) {
        if(tvList[i]->getTitle() == title) {
            cout << "Found TV show: " << tvList[i]->displayInfo() << endl;
            found = true;
        }
    }

    // check music
    for(int i = 0; i < musicCount; i++) {
        if(musicList[i]->getTitle() == title) {
            cout << "Found music: " << musicList[i]->displayInfo() << endl;
            found = true;
        }
    }

    if(!found) {
        cout << "Couldn't find anything called " << title << endl;
    }
}
void Database::saveToFiles() {
    // save movies
    ofstream movieFile;
    movieFile.open("movies.csv");
    if(movieFile.is_open()) {
        // write header
        movieFile << "tt,title,year,genre,rating,director\n";
        
        // write all movies
        for(int i = 0; i < movieCount; i++) {
            movieFile << "tt" << movieList[i]->getId() << ","
                     << movieList[i]->getTitle() << ","
                     << movieList[i]->getYear() << ","
                     << movieList[i]->getGenre() << ","
                     << movieList[i]->getRating() << ","
                     << ((movies::Movie*)movieList[i])->getDirector() << endl;
        }
        movieFile.close();
    }

    // save tv shows
    ofstream tvFile;
    tvFile.open("tvshows.csv");
    if(tvFile.is_open()) {
        // write header
        tvFile << "tmdb,title,year,genre,rating,episodes\n";
        
        // write all shows
        for(int i = 0; i < tvCount; i++) {
            tvFile << "tmdb" << tvList[i]->getId() << ","
                   << tvList[i]->getTitle() << ","
                   << tvList[i]->getYear() << ","
                   << tvList[i]->getGenre() << ","
                   << tvList[i]->getRating() << ","
                   << ((tvshows::TvShow*)tvList[i])->getEpisodes() << endl;
        }
        tvFile.close();
    }

    // save music
    ofstream musicFile;
    musicFile.open("music.csv");
    if(musicFile.is_open()) {
        // write header
        musicFile << "mw,title,year,composer,genre,tracks,playtime\n";
        
        // write all music
        for(int i = 0; i < musicCount; i++) {
            musicFile << "mw" << musicList[i]->getId() << ","
                     << musicList[i]->getTitle() << ","
                     << musicList[i]->getYear() << ","
                     << ((music::Music*)musicList[i])->getComposer() << ","
                     << musicList[i]->getGenre() << ","
                     << ((music::Music*)musicList[i])->getTracks() << ","
                     << ((music::Music*)musicList[i])->getPlaytime() << endl;
        }
        musicFile.close();
    }
}