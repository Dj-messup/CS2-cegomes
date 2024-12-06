#include "TvShows.h"
#include <sstream>  // For stringstream to format the displayInfo output
using namespace std;  // Now you don't need to prefix string with std::

namespace tvshows {

    // Constructor
    Tvshow::Tvshow(int id, string title, int year, string genre, double rating, int numEpisodes)
        : Media(id, title, year), genre(genre), rating(rating), numEpisodes(numEpisodes) {}

    // Getter for genre
    string Tvshow::getGenre() const {
        return genre;
    }

    // Setter for genre
    void Tvshow::setGenre(const string& genre) {
        this->genre = genre;
    }

    // Getter for rating
    double Tvshow::getRating() const {
        return rating;
    }

    // Setter for rating
    void Tvshow::setRating(double rating) {
        this->rating = rating;
    }

    // Getter for numEpisodes
    int Tvshow::getNumEpisodes() const {
        return numEpisodes;
    }

    // Setter for numEpisodes
    void Tvshow::setNumEpisodes(int numEpisodes) {
        this->numEpisodes = numEpisodes;
    }

    // Overridden displayInfo function
    string Tvshow::displayInfo() const {
        stringstream ss;
        ss << "TV Show ID: " << getId() << "\n"
           << "Title: " << getTitle() << "\n"
           << "Year: " << getYear() << "\n"
           << "Genre: " << genre << "\n"
           << "Rating: " << rating << "\n"
           << "Number of Episodes: " << numEpisodes << "\n";
        return ss.str();
    }

}
