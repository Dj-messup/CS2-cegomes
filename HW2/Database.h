#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Movie.h"
#include "Music.h"
#include "TVShow.h"

namespace movies {

    class Database {
    private:
        std::vector<Movie*> movies;
        std::vector<Music*> music;
        std::vector<TVShow*> tvShows;
        std::string name;
        int id;

    public:
        Database(std::string dbName, int dbId) : name(dbName), id(dbId) {}

        ~Database() {
            for (auto movie : movies) delete movie;
            for (auto musicItem : music) delete musicItem;
            for (auto tvShow : tvShows) delete tvShow;
        }

        void addMovie(Movie* movie) {
            movies.push_back(movie);
            saveMoviesToFile("movies.csv");
        }

        void addMusic(Music* musicItem) {
            music.push_back(musicItem);
            saveMusicToFile("music.csv");
        }

        void addTVShow(TVShow* tvShow) {
            tvShows.push_back(tvShow);
            saveTVShowsToFile("tvshows.csv");
        }

        void removeMovie(const std::string& imdbId) {
            auto it = std::remove_if(movies.begin(), movies.end(), [&imdbId](Movie* movie) {
                return movie->getImdbId() == imdbId;
            });
            movies.erase(it, movies.end());
            saveMoviesToFile("movies.csv");
        }

        void removeMusic(const std::string& trackId) {
            auto it = std::remove_if(music.begin(), music.end(), [&trackId](Music* musicItem) {
                return musicItem->getTrackId() == trackId;
            });
            music.erase(it, music.end());
            saveMusicToFile("music.csv");
        }

        void removeTVShow(const std::string& imdbId) {
            auto it = std::remove_if(tvShows.begin(), tvShows.end(), [&imdbId](TVShow* tvShow) {
                return tvShow->getImdbId() == imdbId;
            });
            tvShows.erase(it, tvShows.end());
            saveTVShowsToFile("tvshows.csv");
        }

        void displayAllMovies() const {
            for (auto movie : movies) {
                movie->display();
            }
        }

        void displayAllMusic() const {
            for (auto musicItem : music) {
                musicItem->display();
            }
        }

        void displayAllTVShows() const {
            for (auto tvShow : tvShows) {
                tvShow->display();
            }
        }

        // Saving to CSV files
        void saveMoviesToFile(const std::string& filename) {
            std::ofstream outFile(filename);
            if (outFile.is_open()) {
                for (auto movie : movies) {
                    outFile << movie->getImdbId() << "," << movie->getTitle() << ","
                            << movie->getYear() << "," << movie->getGenre() << ","
                            << movie->getRating() << "\n";
                }
                outFile.close();
            }
        }

        void saveMusicToFile(const std::string& filename) {
            std::ofstream outFile(filename);
            if (outFile.is_open()) {
                for (auto musicItem : music) {
                    outFile << musicItem->getTrackId() << "," << musicItem->getTitle() << ","
                            << musicItem->getArtist() << "," << musicItem->getGenre() << ","
                            << musicItem->getRating() << "\n";
                }
                outFile.close();
            }
        }

        void saveTVShowsToFile(const std::string& filename) {
            std::ofstream outFile(filename);
            if (outFile.is_open()) {
                for (auto tvShow : tvShows) {
                    outFile << tvShow->getImdbId() << "," << tvShow->getTitle() << ","
                            << tvShow->getYear() << "," << tvShow->getGenre() << ","
                            << tvShow->getRating() << "\n";
                }
                outFile.close();
            }
        }

        // Loading from CSV files
        void loadMoviesFromFile(const std::string& filename) {
            std::ifstream inFile(filename);
            std::string line;
            while (getline(inFile, line)) {
                std::stringstream ss(line);
                std::string imdbId, title, genre;
                int year;
                float rating;
                getline(ss, imdbId, ',');
                getline(ss, title, ',');
                ss >> year;
                ss.ignore();
                getline(ss, genre, ',');
                ss >> rating;

                Movie* newMovie = new Movie(imdbId, title, year, genre, rating);
                movies.push_back(newMovie);
            }
            inFile.close();
        }

        void loadMusicFromFile(const std::string& filename) {
            std::ifstream inFile(filename);
            std::string line;
            while (getline(inFile, line)) {
                std::stringstream