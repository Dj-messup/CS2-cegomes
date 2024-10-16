#include "database.h"
#include <iostream>
#include <fstream>

namespace movies {

    Database::Database(const std::string& name, int id) : name(name), db_id(id), movieCount(0) {}

    Database::~Database() {
        for (int i = 0; i < movieCount; ++i) {
            delete movieList[i];
        }
    }

    void Database::addMovie(Movie* movie) {
        if (movieCount < 100) {
            movieList[movieCount++] = movie;
            std::cout << "Movie added: " << movie->getTitle() << std::endl;
        } else {
            std::cout << "Database full. Cannot add more movies." << std::endl;
        }
    }

    void Database::removeMovie(const std::string& imdb_title_id) {
        for (int i = 0; i < movieCount; ++i) {
            if (movieList[i]->getImdbTitleId() == imdb_title_id) {
                delete movieList[i];
                for (int j = i; j < movieCount - 1; ++j) {
                    movieList[j] = movieList[j + 1];
                }
                --movieCount;
                std::cout << "Movie removed." << std::endl;
                return;
            }
        }
        std::cout << "Movie not found." << std::endl;
    }

    void Database::displayAllMovies() const {
        for (int i = 0; i < movieCount; ++i) {
            std::cout << movieList[i]->getTitle() << " (" << movieList[i]->getYear() << "), Genre: " 
                      << movieList[i]->getGenre() << ", Rating: " << movieList[i]->getRating() 
                      << ", Director: " << movieList[i]->getDirector() << std::endl;
        }
    }

    void Database::searchMoviesByTitle(const std::string& title) const {
        for (int i = 0; i < movieCount; ++i) {
            if (movieList[i]->getTitle() == title) {
                std::cout << "Found: " << movieList[i]->getTitle() << std::endl;
                return;
            }
        }
        std::cout << "No movie found with title: " << title << std::endl;
    }

    void Database::searchMoviesByGenre(const std::string& genre) const {
        for (int i = 0; i < movieCount; ++i) {
            if (movieList[i]->getGenre() == genre) {
                std::cout << "Found: " << movieList[i]->getTitle() << std::endl;
            }
        }
    }

    void Database::saveToFile(const std::string& filename) const {
        std::ofstream outFile(filename);
        for (int i = 0; i < movieCount; ++i) {
            outFile << movieList[i]->getImdbTitleId() << "," << movieList[i]->getTitle() << "," << movieList[i]->getYear()
                    << "," << movieList[i]->getGenre() << "," << movieList[i]->getRating() << "," << movieList[i]->getDirector() << std::endl;
        }
        outFile.close();
        std::cout << "Database saved to " << filename << std::endl;
    }
}
