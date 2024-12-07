#include "Database.h"
#include <iostream>
#include <fstream>

using namespace std;

namespace movies {

    // Constructor to initialize the database with a name and ID
    Database::Database(const string& dbName, int dbId)
        : name(dbName), dbId(dbId), movieCount(0) {}

    // Destructor to delete all movies and free memory
    Database::~Database() {
        for (int i = 0; i < movieCount; ++i) {
            delete movieList[i];  // Delete each movie object
        }
    }

    // Load movies from a file (e.g., "movies.csv")
    void Database::loadMoviesFromFile() {
        ifstream fin("movies.csv");  // Open the file for reading
        if (!fin) {
            cout << "Error opening file." << endl;
            return;  // Stop if file can't be opened
        }

        string line;
        while (getline(fin, line)) {
            // Here, you would typically parse the line and create a new movie object
            // This can be extended later if needed
        }
        fin.close();  // Close the file
    }

    // Add a movie to the database
    void Database::addMovie(Movie* newMovie) {
        if (movieCount < 100) {  // Ensure there is space in the database
            movieList[movieCount++] = newMovie;  // Add movie to list and increment count

            // save the movie to a file
            ofstream fout("movies.csv", ios::app);  // Open the file for appending
            fout << newMovie->getImdbId() << ","
                 << newMovie->getTitle() << ","
                 << newMovie->getYear() << ","
                 << newMovie->getGenre() << ","
                 << newMovie->getRating() << endl;
            fout.close();  // Close the file after writing
        } else {
            cout << "Database is full. Cannot add more movies." << endl;
        }
    }

    // Remove a movie from the database by its IMDB ID
    void Database::removeMovie(const string& imdbId) {
        for (int i = 0; i < movieCount; ++i) {
            if (movieList[i]->getImdbId() == imdbId) {
                delete movieList[i];  // Delete the movie object
                for (int j = i; j < movieCount - 1; ++j) {
                    movieList[j] = movieList[j + 1];  // Shift the remaining movies
                }
                --movieCount;  // Decrease the movie count
                break;
            }
        }
    }

    // Display all movies in the database
    void Database::displayAllMovies() const {
        if (movieCount == 0) {
            cout << "No movies to display." << endl;
            return;
        }

        for (int i = 0; i < movieCount; ++i) {
            movieList[i]->displayInfo();  // Display each movie's details
        }
    }

    // Save all movies in the database to a new file
    void Database::saveMoviesToNewFile(const string& filename) const {
        ofstream fout(filename);  // Open the file for writing
        if (!fout) {
            cout << "Error opening file for saving." << endl;
            return;
        }

        for (int i = 0; i < movieCount; ++i) {
            fout << movieList[i]->getImdbId() << ","
                 << movieList[i]->getTitle() << ","
                 << movieList[i]->getYear() << ","
                 << movieList[i]->getGenre() << ","
                 << movieList[i]->getRating() << endl;
        }
        fout.close();  // Close the file
    }
}