#pragma once
#include <string>
#include <iostream>

namespace movies {

    // Movie class with attributes and methods
    class Movie {
    private:
        std::string imdbID;  // IMDB ID
        std::string title;   // Title of the movie
        int year;            // Year of release
        std::string genre;   // Genre of the movie
        double rating;       // Rating of the movie

    public:
        // Constructor
        Movie(const std::string& id, const std::string& t, int y, const std::string& g, double r)
            : imdbID(id), title(t), year(y), genre(g), rating(r) {}

        // Display movie info
        void displayInfo() const {
            std::cout << title << " (" << year << ")\n";
            std::cout << "Genre: " << genre << ", Rating: " << rating << std::endl;
        }

        // Getter functions
        std::string getImdbID() const { return imdbID; }
        std::string getTitle() const { return title; }
        int getYear() const { return year; }
        std::string getGenre() const { return genre; }
        double getRating() const { return rating; }
    };
}
