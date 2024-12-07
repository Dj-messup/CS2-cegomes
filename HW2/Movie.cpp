:#include "Movie.h"

using namespace std;

// Constructor to initialize movie details
Movie::Movie(const string& imdbId, const string& title, int year, const string& genre, float rating)
    : imdbId(imdbId), title(title), year(year), genre(genre), rating(rating) {}

// Getter for IMDB ID
string Movie::getImdbId() const {
    return imdbId;
}

// Getter for movie title
string Movie::getTitle() const {
    return title;
}

// Getter for movie release year
int Movie::getYear() const {
    return year;
}

// Getter for movie genre
string Movie::getGenre() const {
    return genre;
}

// Getter for movie rating
float Movie::getRating() const {
    return rating;
}

// Function to display the movie's information
void Movie::displayInfo() const {
    cout << "IMDB ID: " << imdbId << ", Title: " << title
         << ", Year: " << year << ", Genre: " << genre
         << ", Rating: " << rating << endl;
}