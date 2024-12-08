#include "Database.h"
#include <iostream>
#include <fstream>
using namespace std;

Database::Database() {
    movieCount = 0;
    tvCount = 0;
    musicCount = 0;
    
    for(int i = 0; i < 100; i++) {
        movieList[i] = NULL;
    }
    for(int i = 0; i < 100; i++) {
        tvList[i] = NULL;
    }
    for(int i = 0; i < 100; i++) {
        musicList[i] = NULL;
    }
}

void Database::loadFile(string filename) {
    ifstream inFile;
    inFile.open(filename);
    
    if(!inFile.is_open()) {
        cout << "Could not open file: " << filename << endl;
        return;
    }

    string line;
    getline(inFile, line);  // skip header line
    
    while(getline(inFile, line)) {
        if(filename.find("movies") != string::npos) {
            addMovie(line);
        }
        else if(filename.find("tvshows") != string::npos) {
            addTvShow(line);
        }
        else if(filename.find("music") != string::npos) {
            addMusic(line);
        }
    }
    inFile.close();
}

void Database::addMovie(string line) {
    if(movieCount >= 100) {
        cout << "Movie list is full!" << endl;
        return;
    }

    int comma = line.find(',');
    string id = line.substr(0, comma);
    
    line = line.substr(comma + 1);
    comma = line.find(',');
    string title = line.substr(0, comma);
    
    line = line.substr(comma + 1);
    comma = line.find(',');
    string yearStr = line.substr(0, comma);
    
    line = line.substr(comma + 1);
    comma = line.find(',');
    string genre = line.substr(0, comma);
    
    line = line.substr(comma + 1);
    comma = line.find(',');
    string ratingStr = line.substr(0, comma);
    
    string director = line.substr(comma + 1);

    // Convert year and rating
    int year = atoi(yearStr.c_str());
    float rating = atof(ratingStr.c_str());
    int movieId = atoi(id.substr(2).c_str()); 

    movieList[movieCount] = new movies::Movie(movieId, title, year, genre, rating, director);
    movieCount++;
}