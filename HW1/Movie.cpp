#include "movie.h"

namespace movies {

    // Default constructor
    Movie::Movie() : year(0), rating(0.0) {}

    // Parameterized constructor
    Movie::Movie(const std::string& id, const std::string& title, int year, const std::string& genre, double rating, const std::string& director)
        : imdb_title_id(id), title(title), year(year), genre(genre), rating(rating), director(director) {}

    // Getters
    std::string Movie::getImdbTitleId() const { return imdb_title_id; }
    std::string Movie::getTitle() const { return title; }
    int Movie::getYear() const { return year; }
    std::string Movie::getGenre() const { return genre; }
    double Movie::getRating() const { return rating; }
    std::string Movie::getDirector() const { return director; }

    // Setters
    void Movie::setImdbTitleId(const std::string& id) { imdb_title_id = id; }
    void Movie::setTitle(const std::string& title) { this->title = title; }
    void Movie::setYear(int year) { this->year = year; }
    void Movie::setGenre(const std::string& genre) { this->genre = genre; }
    void Movie::setRating(double rating) { this->rating = rating; }
    void Movie::setDirector(const std::string& director) { this->director = director; }
}
