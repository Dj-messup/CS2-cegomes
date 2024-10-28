#ifndef DATABASE_H
#define DATABASE_H

#include "Movie.h"
#include <string>

namespace movies {

    class Database {
    private:
        std::string name;
        int db_id;
        Movie* movieList[100];
        int movieCount;

    public:
        // Constructor
        Database(const std::string& name, int id);

        // Destructor
        ~Database();

        // Methods
        void addMovie(Movie* movie);
        void removeMovie(const std::string& imdb_title_id);
        void displayAllMovies() const;
        void searchMoviesByTitle(const std::string& title) const;
        void searchMoviesByGenre(const std::string& genre) const;
        void saveToNewFile(const std::string& filename) const;
    };
}

#endif
