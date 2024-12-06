#include "Music.h"
#include <sstream>  // For stringstream to format the displayInfo output
using namespace std;  // Now you don't need to prefix string with std::

namespace music {

    // Constructor
    Music::Music(int id, string title, int year, string composer, string genre, int numTracks, double totalPlaytime)
        : Media(id, title, year), composer(composer), genre(genre), numTracks(numTracks), totalPlaytime(totalPlaytime) {}

    // Getter for composer
    string Music::getComposer() const {
        return composer;
    }

    // Setter for composer
    void Music::setComposer(const string& composer) {
        this->composer = composer;
    }

    // Getter for genre
    string Music::getGenre() const {
        return genre;
    }

    // Setter for genre
    void Music::setGenre(const string& genre) {
        this->genre = genre;
    }

    // Getter for numTracks
    int Music::getNumTracks() const {
        return numTracks;
    }

    // Setter for numTracks
    void Music::setNumTracks(int numTracks) {
        this->numTracks = numTracks;
    }

    // Getter for totalPlaytime
    double Music::getTotalPlaytime() const {
        return totalPlaytime;
    }

    // Setter for totalPlaytime
    void Music::setTotalPlaytime(double totalPlaytime) {
        this->totalPlaytime = totalPlaytime;
    }

    // Overridden displayInfo function
    string Music::displayInfo() const {
        stringstream ss;
        ss << "Music ID: " << getId() << "\n"
           << "Title: " << getTitle() << "\n"
           << "Year: " << getYear() << "\n"
           << "Composer: " << composer << "\n"
           << "Genre: " << genre << "\n"
           << "Number of Tracks: " << numTracks << "\n"
           << "Total Playtime: " << totalPlaytime << " mins\n";
        return ss.str();
    }

}
