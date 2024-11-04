#include "Database.h"
#include <iostream>
#include <fstream>

namespace movies {

    // Constructor Db w/ name and id
    Database::Database(const std::string& name, int id) : name(name), db_id(id), movieCount(0) {}

    // Destructor to free memory
    Database::~Database() {
        for (int i = 0; i < movieCount; ++i) {
            delete movieList[i];  // Free dynamically allocated movies
        }
    }

    // Add movie to the db (if avail to do so)
    void Database::addMovie(Movie* movie) {
        if (movieCount < 100) {  // Ensure database does not exceed 100 movies
            movieList[movieCount++] = movie;  // Add movie to the array
            std::cout << "Movie added: " << movie->getTitle() << std::endl;
        } else {
            std::cout << "Database full. Cannot add more movies." << std::endl;
        }
    }

    // Remove movie based on IMDb title ID
    void Database::removeMovie(const std::string& imdb_title_id) {
        for (int i = 0; i < movieCount; ++i) {
            if (movieList[i]->getImdbTitleId() == imdb_title_id) {  // Find movie by ID
                delete movieList[i];  // Delete movie object
                for (int j = i; j < movieCount - 1; ++j) {
                    movieList[j] = movieList[j + 1];  // Shift remaining movies
                }
                --movieCount;  // Decrement
                std::cout << "Movie removed." << std::endl;
                return;
            }
        }
        std::cout << "Movie not found." << std::endl;
    }

    // Display all movies in the db
    void Database::displayAllMovies() const {
        for (int i = 0; i < movieCount; ++i) {
            std::cout << movieList[i]->getTitle() << " (" << movieList[i]->getYear() 
                      << "), Genre: " << movieList[i]->getGenre() << ", Rating: " 
                      << movieList[i]->getRating() << ", Director: " << movieList[i]->getDirector() << std::endl;
        }
    }

    // Search by title
    void Database::searchMoviesByTitle(const std::string& title) const {
        for (int i = 0; i < movieCount; ++i) {
            if (movieList[i]->getTitle() == title) {  // Match title
                std::cout << "Found: " << movieList[i]->getTitle() << std::endl;
                return;
            }
        }
        std::cout << "No movie found with title: " << title << std::endl;
    }

    // Search by genre
    void Database::searchMoviesByGenre(const std::string& genre) const 
    {
        for (int i = 0; i < movieCount; ++i) 
        {
            if (movieList[i]->getGenre() == genre) 
            {  // Match genre
                std::cout << "Found: " << movieList[i]->getTitle() << std::endl;
            }
        }
    }

    // Save to CSV file
    void Database::saveToNewFile(const std::string& filename) const 
    {
    std::ofstream outFile(filename);  // Open the new file for writing
    if (!outFile) 
    {
        std::cout << "Error opening file: " << filename << std::endl;
        return;
    }
    for (int i = 0; i < movieCount; ++i) {
        outFile << movieList[i]->getImdbTitleId() << "," 
                << movieList[i]->getTitle() << "," 
                << movieList[i]->getYear() << "," 
                << movieList[i]->getGenre() << "," 
                << movieList[i]->getRating() << "," 
                << movieList[i]->getDirector() << std::endl;  // Write movie details to the new CSV
    }
    outFile.close();  // Close the file
    std::cout << "Database saved to " << filename << std::endl;
    }
}
