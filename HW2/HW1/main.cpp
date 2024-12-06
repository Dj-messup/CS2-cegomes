#include <iostream>
#include <string>
#include "Database.h"
#include "Movie.h"

using namespace std;
using namespace movies;

int main() {
    // Create a database for movies
    Database db("Movie Database", 1);

    // Add some movies
    Movie* movie1 = new Movie("tt0111161", "The Shawshank Redemption", 1994, "Drama", 9.3);
    Movie* movie2 = new Movie("tt0068646", "The Godfather", 1972, "Crime", 9.2);

    db.addMovie(movie1);  // Add first movie
    db.addMovie(movie2);  // Add second movie

    // Show all movies
    db.displayAllMovies();

    // Save movies to a new file
    db.saveToNewFile("new_movies.csv");

    // Clean up memory
    delete movie1;
    delete movie2;

    return 0;
}
