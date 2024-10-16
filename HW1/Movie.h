#ifndef MOVIE_H
#define MOVIE_H

#include <string>

namespace movies {
    //Movie class with private vars
    class Movie {
    private:
        std::string imdb_title_id; // IMDB ID (private vars..)
        std::string title;         
        int year;                  
        std::string genre;         
        double rating;
        std::string director;

    public:
        // Constructors
        Movie();
        Movie(const std::string& id, const std::string& title, int year, const std::string& genre, double rating, const std::string& director);

        // Getters (methods to get private vars)
        std::string getImdbTitleId() const;
        std::string getTitle() const;
        int getYear() const;
        std::string getGenre() const;
        double getRating() const;
        std::string getDirector() const;

        // Setters (methods to set private vars)
        void setImdbTitleId(const std::string& id);
        void setTitle(const std::string& title);
        void setYear(int year);
        void setGenre(const std::string& genre);
        void setRating(double rating);
        void setDirector(const std::string& director);
    };
}

#endif
