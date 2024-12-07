#pragma once
#include <iostream>
#include <string>

namespace movies {

    class Movie {
    private:
        std::string imdbId;
        std::string title;
        int year;
        std::string genre;
        float rating;

    public:
        Movie(std::string imdbId, std::string title, int year, std::string genre, float rating)
            : imdbId(imdbId), title(title), year(year), genre(genre), rating(rating) {}

        std::string getImdbId() const { return imdbId; }
        std::string getTitle() const { return title; }
        int getYear() const { return year; }
        std::string getGenre() const { return genre; }
        float getRating() const { return rating; }

        void display() const {
            std::cout << "IMDB ID: " << imdbId << ", Title: " << title << ", Year: " << year
                << ", Genre: " << genre << ", Rating: " << rating << std::endl;
        }
    };
}