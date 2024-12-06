#include "Database.h"
#include <iostream>
#include <fstream>
#include <string>

namespace movies {

    // Constructor
    Database::Database(const std::string& name, int id) : name(name), db_id(id), movieCount(0) {
        loadFromFile();  // Load movies from file
    }

    // Destructor
    Database::~Database() {
        for (int i = 0; i < movieCount; ++i) {
            delete movieList[i];  // Delete movie
        }
    }

    // Load movies from file
    void Database::loadFromFile() {
        std::ifstream fin("movies.csv");  // Open file
        if (!fin) {
            std::cout << "Error opening file." << std::endl;
            return;  // If error, stop
        }

        std::string line;
        // Read each line
        while (std::getline(fin, line)) {
            // Add movie to list
        }

        fin.close();  // Close file
    }

    // Add movie to list
    void Database::addMovie(Movie* newMovie) {
        if (movieCount < 100) {  // If space available
            movieList[movieCount++] = newMovie;  // Add movie

            // Save movie to file
            std::ofstream fout("movies.csv", std::ios::app);  // Open file
            fout << newMovie->getImdbID() << "," << newMovie->getTitle() << std::endl;
            fout.close();  // Close file
        } else {
            std::cout << "Database full. Cannot add more movies." << std::endl;
        }
    }

    // Remove movie from list
    void Database::removeMovie(const std::string& imdbID) {
        // Find and remove movie
    }

    // Show all movies
    void Database::displayAllMovies() {
        // Display each movie
    }

    // Search movies by title
    void Database::searchMoviesByTitle(const std::string& title) {
        // Search and print movies
    }

    // Search movies by genre
    void Database::searchMoviesByGenre(const std::string& genre) {
        // Search and print movies
    }

    // Save movies to new file
    void Database::saveToNewFile(const std::string& filename) {
        std::ofstream fout(filename);  // Open file
        for (int i = 0; i < movieCount; ++i) {
            fout << movieList[i]->getImdbID() << "," << movieList[i]->getTitle() << std::endl;
        }
        fout.close();  // Close file
    }
}
