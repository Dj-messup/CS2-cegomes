#pragma once
#include "Movie.h"
#include <string>
#include <iostream>
#include <fstream>

namespace movies {

    // Database class to manage movies
    class Database {
    private:
        std::string name;         // Name of the database
        int db_id;                // Database ID
        Movie* movieList[100];    // Array to store movies
        int movieCount;           // Number of movies in the database

    public:
        // Constructor
        Database(const std::string& db_name, int id)
            : name(db_name), db_id(id), movieCount(0) {}

        // Destructor
        ~Database() {
            for (int i = 0; i < movieCount; ++i) {
                delete movieList[i];  // Free allocated memory for movies
            }
        }

        // Add a movie to the database
        void addMovie(Movie* newMovie) {
            if (movieCount < 100) {  // Check if there is space
                movieList[movieCount++] = newMovie;
            }
        }

        // Remove a movie by IMDB ID
        void removeMovie(const std::string& imdbID) {
            for (int i = 0; i < movieCount; ++i) {
                if (movieList[i]->getImdbID() == imdbID) {
                    delete movieList[i];  // Delete the movie
                    for (int j = i; j < movieCount - 1; ++j) {
                        movieList[j] = movieList[j + 1];  // Shift movies
                    }
                    --movieCount;  // Decrease the movie count
                    break;
                }
            }
        }

        // Display all movies in the database
        void displayAllMovies() const {
            for (int i = 0; i < movieCount; ++i) {
                movieList[i]->displayInfo();  // Display each movie's info
            }
        }

        // Save the movies to a new file
        void saveToNewFile(const std::string& filename) const {
            std::ofstream fout(filename);  // Open file for writing
            for (int i = 0; i < movieCount; ++i) {
                fout << movieList[i]->getImdbID() << ","
                     << movieList[i]->getTitle() << ","
                     << movieList[i]->getYear() << ","
                     << movieList[i]->getGenre() << ","
                     << movieList[i]->getRating() << std::endl;
            }
            fout.close();  // Close the file
        }

        // Load movies from a file
        void loadFromFile() {
            std::ifstream fin("movies.csv");  // Open file to read movies
            if (!fin) {
                std::cout << "Error opening file." << std::endl;
                return;  // If error, stop
            }

            std::string line;
            while (std::getline(fin, line)) {
                // Parse the line and add movies (implementation not shown here)
            }

            fin.close();  // Close file
        }
    };
}
