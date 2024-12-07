#include "Movie.h"
#include <iostream>

using namespace std; 

namespace movies {

    // Constructor with no params, in case we need a blank movie (useful for placeholders)
    Movie::Movie() {
        imdb_title_id = "";
        title = "";
        year = 0;
        genre = "";
        rating = 0.0;
        director = "";
    }

    // Constructor with params - sets up the movie when we know its info
    Movie::Movie(const string& id, const string& title, int yr, const string& gen, double rat, const string& dir) {
        imdb_title_id = id;
        this->title = title; // "this->" makes it clear we're setting the class member
        year = yr;
        genre = gen;
        rating = rat;
        director = dir;
    }

    // Getters - Fetch movie details
    string Movie::getImdbTitleId() const { 
        return imdb_title_id; 
    }
    
    string Movie::getTitle() const { 
        return title; 
    }
    
    int Movie::getYear() const { 
        return year; 
    }
    
    string Movie::getGenre() const { 
        return genre; 
    }
    
    double Movie::getRating() const { 
        return rating; 
    }
    
    string Movie::getDirector() const { 
        return director; 
    }

    // Setters - Update movie details
    void Movie::setImdbTitleId(const string& id) { 
        imdb_title_id = id; 
    }
    
    void Movie::setTitle(const string& title) { 
        this->title = title; 
    }
    
    void Movie::setYear(int yr) { 
        year = yr; 
    }
    
    void Movie::setGenre(const string& gen) { 
        genre = gen; 
    }
    
    void Movie::setRating(double rat) { 
        rating = rat; 
    }
    
    void Movie::setDirector(const string& dir) { 
        director = dir; 
    }
}

